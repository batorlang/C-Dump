#include <stdio.h>

int main() {
    int num, sum = 0, digit;

    printf("Give the integer:\n");

    if (scanf("%d", &num) != 1) {
        return 1;
    }

    while (num > 0) {
        digit = num % 10;

        if (digit == 8) {
            break;
        }

        if (digit != 4) {
            sum += (digit * digit);
        }

        num = num/10;
    }

    printf("The summation is %d.\n", sum);

    return 0;

}