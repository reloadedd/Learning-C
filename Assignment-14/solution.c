#include <stdio.h>

int main() {
    int value = 1337;
    int *ptr = &value;

    printf("The value of our pointer is: %d\n", ptr);
}