#include <stdio.h>

int main() {
    int num, count = 0, max = 0;
    float sum = 0.0;

    printf("Enter positive integers (0 to stop):\n");

    scanf("%d", &num);

    while (num != 0) {
        count++;
        sum += num;
        if (num > max) {
            max = num;
        }

        scanf("%d", &num);
    }

    if (count > 0) {
        float avg = sum / count;
        printf("Count: %d\n", count);
        printf("Maximum: %d\n", max);
        printf("Average: %.2f\n", avg);
    } else {
        printf("No numbers were entered.\n");
    }
    return 0;
}