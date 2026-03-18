#include <stdio.h>
#include <string.h>

int main() {
    char sentance[200], *vowelCollection = "aeiouAEIOU";
    int vowels = 0, length = 0;

    printf("Enter a sentence:\n");


    if (fgets (sentance, sizeof(sentance), stdin) != NULL) {
        sentance[strcspn(sentance, "\n")] = '\0';
        length = strlen(sentance);

        for (int i = 0; i < length; i++) {
            if (strchr(vowelCollection, sentance[i]) != NULL) {
                vowels++;
            }
        }
        printf("Number of vowels: %d\n", vowels);
        printf("Number of characters: %d\n", length);
    }

    return 0;
}