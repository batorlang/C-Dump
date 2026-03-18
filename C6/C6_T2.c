#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 4;
    int count = 0;
    int input;

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Enter numbers (enter -1 to stop):\n");

    while (1) {
        printf("Enter a number:\n");
        if (scanf("%d", &input) != 1) {
            break;
        }

        if (input == -1) {
            break;
        }

        array[count++] = input;

        if ((float)count / size >= 0.75) {
            size *= 2;
            array = (int *)realloc(array, size * sizeof(int));
            printf("The array size increases to %d.\n", size);

            if (array == NULL) {
                return 1;
            }
        }
    }

    printf("\nFinal array (with %d elements):", count);
    for (int i = 0; i < count; i++) {
        printf(" %d", array[i]);
    }

    printf("\n");

    free(array);
    return 0;
}