#include <stdio.h>

#define SIZE 10


int main(int argc, char const *argv[])
{
	int array[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		array[i] = i;
	}

	// for (int i = 0; i < SIZE; ++i)
	// {
	// 	printf("%d ", array[i]);
	// }

	printf("%d\n", sizeof(array) / sizeof(int));
	return 0;
}