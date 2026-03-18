#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int birthYear;
    char firstName[50];
    char lastName[50];
    char gender[20];
} Person;

void sortRecordsByBirthYear(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].birthYear > people[j + 1].birthYear) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    char filename[256];
    char line[1024];
    Person people[100];
    int recordCount = 0;

    printf("Enter the file name to be read:\n");
    if (scanf("%255s", filename) != 1) {
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    printf("\nReading CSV file...\n");

    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return 0;
    }

    while (fgets(line, sizeof(line), fp) && recordCount < 100) {
    line[strcspn(line, "\r\n")] = 0;
    if (strlen(line) == 0) continue;

    char *year_str = strtok(line, ",");
    char *first = strtok(NULL, ",");
    char *last = strtok(NULL, ",");
    char *gen = strtok(NULL, ",");

    if (year_str && first && last && gen) {
        people[recordCount].birthYear = atoi(year_str);
        strncpy(people[recordCount].firstName, first, 49);
        strncpy(people[recordCount].lastName, last, 49);
        strncpy(people[recordCount].gender, gen, 19);
        recordCount++;
    }
}

    fclose(fp);
    sortRecordsByBirthYear(people, recordCount);
    printf("\nSorted Records (by Birth Year):\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Birth Year: %d, Name: %s %s, Gender: %s\n", 
               people[i].birthYear,
               people[i].firstName, 
               people[i].lastName, 
               people[i].gender);
    }

    return 0;
}