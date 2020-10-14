#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

ssize_t write(int fd, const void *buf, size_t count) {
	// The new, modified version of the write syscall
	ssize_t (*malicious_write)(int fd, const void *buf, size_t count);

	// The number of bytes written, returned by the legit write
	ssize_t bytes_written;

	malicious_write = dlsym(RTLD_NEXT, "write");

	if (strcmp((const char *)buf, "Hello, World!") == 0) {
		bytes_written = malicious_write(fd, "Goodbye, cruel world!", 22);
	}else{
		bytes_written = malicious_write(fd, buf, count);
	}

	return bytes_written;
}