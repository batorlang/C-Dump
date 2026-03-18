#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char str[100];
    int choice;

    printf("Enter a string:\n");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }

    printf("Choose operation:\n");
    printf("1. Uppercase\n");
    printf("2. Lowercase\n");
    printf("Enter your choice:\n");
    if (scanf("%d", &choice) != 1) {
        return 1;
    }

    void (*stringFunctions[])(char*) = {toUpperCase, toLowerCase};
    if (choice >= 1 && choice <= 2) {
        stringFunctions[choice - 1](str);
        printf("Processed String: %s\n", str);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
