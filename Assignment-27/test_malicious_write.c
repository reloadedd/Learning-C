#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	write(1, "Hello, World!", 14);
	// printf("Hello, World!");
	return 0;
}