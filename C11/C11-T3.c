#include <stdio.h>
#include <stdlib.h>

int main() {
    int seed;
    printf("Give me your seed:\n");
    if (scanf("%d", &seed) != 1) {
        return 1;
    }
    srand(seed);
    for (int i = 0; i<5; i++) {
        int random = (rand() % 100)+1;
        printf("%d", random);

        if (i<4) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}