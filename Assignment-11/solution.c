#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SIZE = 1;

int main(int argc, char const *argv[])
{
	int *array = malloc(SIZE * sizeof(int)), sum;
	float average;
	char answer[] = "Y";

	while ((strcmp(answer, "Y") == 0)) { 
		printf("Enter a test score >>> ");
		scanf("%d", &array[SIZE - 1]);

		printf("Would you like to continue? Y/N >>> ");
		scanf("%s", answer);

		if (strcmp(answer, "Y") == 0) {
			SIZE++;
			array = realloc(array, SIZE * sizeof(int));
		}
	}

	sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += array[i];
	}

	average = sum / (SIZE * 1.0);
	printf("%.2f is the average\n", average);

	return 0;
}