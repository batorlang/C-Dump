#include <stdio.h>
#include <string.h>

void swapElements(char str[], int index1, int index2) {
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
}

int main() {
    char inputStr[100];
    int idx1, idx2;
    int length;

    printf("Enter a string:\n");
    if (fgets(inputStr, sizeof(inputStr), stdin) != NULL) {
        inputStr[strcspn(inputStr, "\n")] = '\0';
    }

    printf("Enter first index:\n");
    scanf("%d", &idx1);

    printf("Enter second index:\n");
    scanf("%d", &idx2);

    length = strlen(inputStr);

    if (idx1 >= 0 && idx1 < length && idx2 >= 0 && idx2 < length) {
        swapElements(inputStr, idx1, idx2);
        printf("Modified string: %s\n", inputStr);
    } else {
        printf("Indices are out of bounds.\n");
    }

    return 0;
}