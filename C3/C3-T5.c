#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200], *delimeters = "aeiouAEIOU", *token;

    printf("Please enter a string:\n");
    if (scanf("%200s", sentence) != 1) {
        return 1;
    }

    printf("Splitting the string by vowels:\n");

    token = strtok(sentence, delimeters);
    while (token != 0) {
        printf("%s\n", token);
        token = strtok(NULL, delimeters);
    }

    return 0;
    
}