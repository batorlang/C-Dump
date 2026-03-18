#include <stdio.h>

char asciiToChar(int asciiValue) {
    return (char)asciiValue;
}

int charToAscii(char c) {
    return (int)c;
}

int main() {
    int choice;
    int asciiInput;
    char charInput;

    do {
        printf("Menu:\n");
        printf("1. Convert ASCII value to character\n");
        printf("2. Convert character to ASCII value\n");
        printf("0. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter an ASCII value:\n");
            scanf("%d", &asciiInput);

            char result = asciiToChar(asciiInput);
            printf("The character for ASCII value %d is '%c'.\n", asciiInput, result);
            printf("\n");

        } else if (choice == 2) {
            printf("Enter a character:\n");

            scanf(" %c", &charInput);
            
            int result = charToAscii(charInput);
            printf("The ASCII value for character '%c' is %d.\n", charInput, result);
            printf("\n");

        } else if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
        }

    } while (choice != 0);

    return 0;
}