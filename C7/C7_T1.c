#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    char name[50];
    float score;
} Student;

float average(Student** students, size_t n) {
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++) {
        if (students[i] != NULL) {
            sum += students[i]->score;
        }
    }
    return sum / (float)n;
}

int main() {
    int stud_count;
    printf("Enter the number of students: ");
    scanf("%d", &stud_count);
    Student** students = (Student**)malloc(stud_count * sizeof(Student*));

    for (int i = 0; i < stud_count; i++) {
        char temporary_name[50];
        float temporary_score;
        students[i] = malloc(sizeof(Student));
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", temporary_name);

        printf("Enter score for student %d: ", i + 1);
        scanf("%f", &temporary_score);

        Student *new_student = (Student*)malloc(sizeof(Student));
        if (new_student == NULL) {
            puts("Memory allocation failed");
            return 1;
        }
        strcpy(new_student->name, temporary_name);
        new_student->score = temporary_score;
        students[i] = new_student;

    }
    float avg = average(students, stud_count);
    printf("\nThe average score of %d students is: %.2f\n", stud_count, avg);

    for (int i = 0; i < stud_count; i++) {
        free(students[i]);
    }
    free(students);
    return 0;
}