#include <stdio.h>


int isBitPalindrome(unsigned int num) {
    if (num == 0 || num == 1) {
        return 1;
    }

    unsigned int original = num;
    unsigned int rev = 0;

    while (num > 0) {
        rev = rev << 1;
        rev |= (num & 1);
        num = num >> 1;
    }

    if (rev == original) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    unsigned int input;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &input) == 1) {
        if (isBitPalindrome(input)) {
            printf("Palindrome\n");
        } else {
            printf("Not palindrome\n");
        }
    }
    return 0;
}