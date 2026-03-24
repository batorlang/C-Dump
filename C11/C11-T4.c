#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} Athlete;

int compare_athletes(const void *a, const void *b) {
    const Athlete *athA = (const Athlete *)a;
    const Athlete *athB = (const Athlete *)b;
    if (athA->score > athB->score) {
        return -1;
    } else if (athA->score < athB->score) {
        return 1;
    } else {
        return strcmp(athA->name, athB->name);
    }
}

int main() {
    Athlete athletes[5];
    for (int i = 0; i < 5; i++) {
        printf("Please input %d athlete info", i+1);
        if (scanf("%19s %d", athletes[i].name, &athletes[i].score) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    qsort(athletes, 5, sizeof(Athlete), compare_athletes);
    printf("\nRanking:\n");
    for (int i = 0; i<5; i++) {
        printf("%s %d\n", athletes[i].name, athletes[i].score);
    }
    return 0;

}