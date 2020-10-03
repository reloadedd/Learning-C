#include <stdio.h>
#include <stdlib.h>

#define SIZE    10

int main() {
    char *ptr = malloc(SIZE * sizeof(char));

    if (ptr == NULL) {
        printf("Memory allocation failure.\n");
    }else{
        printf("Memory successfully allocated.\n");
        return 1;
    }

    return 0;
}