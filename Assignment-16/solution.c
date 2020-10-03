#include <stdio.h>

#define NO_OF_ELEMENTS  10

int main() {
    int array[NO_OF_ELEMENTS];

    printf("Method #1: Value of the array -> %d\n", array);
    printf("Method #2: Value of the array -> %d\n", &array[0]);
}