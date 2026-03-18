#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    char line[1024];

    printf("Enter the file name to be read:\n");
    if (scanf("%255s", filename) != 1) {
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    printf("\nReading csv file...\n");

    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) {
            continue;
        }

        char *birthyear_str = strtok(line, ",");
        char *first_name = strtok(NULL, ",");
        char *last_name = strtok(NULL, ",");
        char *gender = strtok(NULL, ",");

        if (birthyear_str && first_name && last_name && gender) {
            int birthyear = atoi(birthyear_str);
            int age_in_2100 = 2100 - birthyear;

            printf("Name: %s %s, Gender: %s, Birth Year: %d, Age in 2100: %d\n",
                   first_name, last_name, gender, birthyear, age_in_2100);
        }
    }
    
    fclose(fp);

    return 0;
}