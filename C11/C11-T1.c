#include <stdio.h>
#include <time.h>

int main() {
    long st_input, ed_input;
    printf("Please input two integers:\n");
    if (scanf("%ld %ld", &st_input, &ed_input) != 2) {
        printf("Invalid input");
        return 1;
    }
    time_t start = (time_t)st_input;
    time_t end = (time_t)ed_input;

    char* into_string = ctime(&start);
    double diff = difftime(end, start);
    printf("Start: %s", into_string);
    printf("Duration: %.2f seconds\n", diff);
    return 0;
}