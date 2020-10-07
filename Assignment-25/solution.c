#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


#define FILENAME	"testfile.txt"

int main(int argc, char const *argv[])
{
	int fd;
	
	// Open the file
	if ((fd = open(FILENAME, O_WRONLY | O_CREAT, S_IRWXU)) == -1) {
		printf("[ ERROR ] Could not open the file!\n");
		return -1;
	}else{
		printf("[ INFO ] File '%s' created successfully!\n", FILENAME);
	}


	int bytes_written, bytes_to_write = 48;
	if ((bytes_written = write(fd, "Writing to the file using the write() syscall.\n", bytes_to_write)) != bytes_to_write) {
		printf("[ ERROR ] Something bad happened.\n");
		return -1;
	}else{
		printf("[ INFO ] Successfully wrote to the file.\n");
	}


	close(fd);

	return 0;
}