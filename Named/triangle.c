#include <stdio.h>

int main() {
    int height;


    printf("Give the height (max 20): ");
    scanf("%d", &height);

    if (height < 1 || height > 20) {
        printf("height should be between 1 and 20!\n");
        return 0;
    }

    for (int i=1; i <= height -1; i++) {

        for (int x = 0; x <= height -i -1; x++) {
            printf("%c", ' ');
        }
        for (int j = 1; j <= i; j++) {
            printf("%c", '*');
        }
        printf("%c", '\n');
    } 
    
    return 0;
}