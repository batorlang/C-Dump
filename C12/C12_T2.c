#include <stdio.h>

void printBinary(unsigned int num) {
    int i;
    int flag = 0;
    for (i=31; i>=0; i--) {
        unsigned int bits = (num >> i) & 1;

        if (bits == 1) {
            flag = 1;
        }

        if (flag) {
            printf("%u", bits);
        }
    }

    if(!flag) {
        printf("0");
    }
}


int main() {
    unsigned int input;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &input) ==1){
        printf("Binary representation: ");
        printBinary(input);
        printf("\n");
    }
    return 0;

}