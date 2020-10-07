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
		return 0;
	}




	return 0;
}