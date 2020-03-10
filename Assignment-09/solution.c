#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc < 3) {
		printf("Too few arguments!\n");
		printf("Usage: %s <first_name> <last_name>\n", argv[0]);
		return 0;
	}else if (argc > 3) {
		printf("Too many arguments!\n");
		printf("Usage: %s <first_name> <last_name>\n", argv[0]);
		return 0;
	}

	printf("Welcome, %s %s\n", argv[1], argv[2]);
	return 0;
}