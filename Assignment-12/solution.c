#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int coin_flips, heads = 0, tails = 0;

	/* Initialize the random number generator */
	srand(time(NULL));

	printf("How many times would you like to flip the coins ? ");
	scanf("%d", &coin_flips);

	for (int i = 0; i < coin_flips; ++i)
	{
		int flip = rand() % 2;
		if (flip) {
			heads++;
		}else{
			tails++;
		}
	}

	printf("After flipping the coin %d times, the results were\n", coin_flips);
	printf("%d heads\n", heads);
	printf("%d tails\n", tails);

	return 0;
}