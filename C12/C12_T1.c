#include <stdio.h>

struct Student {
    int ID;
    char name[50];
    float GPA;
};

int main() {
    FILE* file;
    struct Student student1;
    file = fopen("students.bin", "rb");
    if (file == NULL) {
        printf("Error occured while opening the file");
        return 1;
    }
    fseek(file, 2 * sizeof(struct Student), SEEK_SET);
    if (fread(&student1, sizeof(struct Student), 1, file) == 1){
        printf("ID: %d, Name: %s, GPA: %.2f\n", student1.ID, student1.name, student1.GPA);
    }

    fclose(file);
    return 0;

}
