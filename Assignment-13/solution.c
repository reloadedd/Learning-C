#include <stdio.h>

#define PLAYERS 5
#define GAMES   4

int main() {
    int score[GAMES][PLAYERS] = {0};
    float average_scores[PLAYERS] = {0};

    // Getting the scores for each player at each game played
    for (int i = 0; i < GAMES; ++i) {
        printf("Game #%d\n", i + 1);
        for (int j = 0; j < PLAYERS; ++j) {
            printf("Enter scoring total for Player #%d: ", j + 1);
            scanf("%d", &score[i][j]);
        }
    }

    // Computing the average scores for all players 
    for (int i = 0; i < PLAYERS; ++i) {
        for (int j = 0; j < GAMES; ++j) {
            average_scores[i] += score[j][i];
        }
        average_scores[i] /= GAMES;
    }

    int max = 0;
    for (int i = 1; i < PLAYERS; ++i) {
        if (average_scores[i] > average_scores[max]) {
            max = i;
        }
    }

    printf("Player #%d had the highest scoring average at %f points per game.\n", max + 1, average_scores[max]);
    return 0;
}