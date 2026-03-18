#include <stdio.h>

void countUntil() {
    int n, sum = 0;

    printf("Please enter an integer greater than 0:\n");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Stopping: the number must be greater than zero.\n");
    } else {
        // Loop from 0 to n to calculate the sum
        for (int i = 0; i <= n; i++) {
            sum += i;
        }
        printf("The sum of integers from 0 to %d is: %d\n", n, sum);
    }
}
int main() {
    countUntil();
    return 0;
}