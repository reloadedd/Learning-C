#include <stdio.h>

int main(int argc, char const *argv[])
{
	int number;

	printf("Enter a number between 1 and 500 >>> \n");
	scanf("%d", &number);

	if (number >= 1 && number <= 100) {
		printf("Your number is between 1 and 100\n");
	}else if (number >= 101 && number <= 200) {
		printf("Your number is between 101 and 200\n");
	}else if (number >= 201 && number <= 300) {
		printf("Your number is between 201 and 300\n");
	}else if (number >= 301 && number <= 400) {
		printf("Your number is between 301 and 400\n");
	}else if (number >= 401 && number <= 500) {
		printf("Your number is between 401 and 500\n");
	}else{
		printf("Number out of range!\n");
	}

	return 0;
}