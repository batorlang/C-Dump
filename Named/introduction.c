#include <stdio.h>

int main() {
    char name[20];
    int age;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Give your age: ");
    scanf("%d", &age);

    printf("Hello, %s! You are %d years old.\n", name, age);
    return 0;
}