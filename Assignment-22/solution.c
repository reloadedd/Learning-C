#include <stdio.h>

#define NO_OF_PLAYERS 	5

struct stats {
	int points;
	int games;
} player[NO_OF_PLAYERS];


int main(int argc, char const *argv[])
{
	// Getting user input
	for (int i = 0; i < NO_OF_PLAYERS; ++i) {
		printf("Enter Player %d's point total: ", i + 1);
		scanf("%d", &player[i].points);
		printf("Enter Player %d's game total: ", i + 1);
		scanf("%d", &player[i].games);
	}

	// Printing the results
	for (int i = 0; i < NO_OF_PLAYERS; ++i) {
		printf("Player %d's scoring average was %.2f ppg.\n", i + 1, (float)player[i].points / player[i].games);
	}

	return 0;
}