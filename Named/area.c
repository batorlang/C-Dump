#include <stdio.h>

int main() {
    double num1, num2;
    printf("Width: ");
    scanf("%le", &num1);
    printf("Height: ");
    scanf("%le" , &num2);
    double area = num1 * num2;
    printf("Area: %le\n", area);
    return 0;
}

