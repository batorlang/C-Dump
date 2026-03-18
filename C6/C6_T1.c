#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    long read;

    printf("Welcome to the Echo Machine! (Press Ctrl+D to finish)\n");
    printf("Please enter anything:\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("You entered: %s \n", line);
        printf("Please enter anything:\n");
    
    }
    free(line);
    return 0;
}