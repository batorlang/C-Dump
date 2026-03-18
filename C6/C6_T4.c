#include <stdio.h>

int main() {
    FILE *fp = fopen("chap6_task4_output.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    char name[100];
    int age;
    char gender[50];
    char choice;

    do {
        printf("Enter name (without spaces):\n");
        scanf("%s", name);
        printf("Enter age:\n");
        scanf("%d", &age);
        printf("Enter gender:\n");
        scanf("%s", gender);
        fprintf(fp, "%s,%d,%s\n", name, age, gender);
        printf("Do you want to add another person? (y/n):\n");

        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    fclose(fp);

    printf("Data saved successfully to chap6_task4_output.txt.\n");

    return 0;
}