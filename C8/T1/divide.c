#include "divide.h"
#include <stdio.h>

float divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0.0;
    } else {return (float)a / b;}

}