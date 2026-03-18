#include <stdio.h>

int main() {
    printf("unsigned char is %d bytes\n", (int)sizeof(unsigned char));
    printf("char is %d bytes\n", (int)sizeof(char));
    printf("int is %d bytes\n", (int)sizeof(int));
    printf("unsigned int is %d bytes\n", (int)sizeof(unsigned int));
    printf("long is %d bytes\n", (int)sizeof(long));
    printf("unsigned long is %d bytes\n", (int)sizeof(unsigned long));
    printf("long long is %d bytes\n", (int)sizeof(long long));
    printf("unsigned long long is %d bytes\n", (int)sizeof(unsigned long long));
    printf("float is %d bytes\n", (int)sizeof(float));
    printf("double is %d bytes\n", (int)sizeof(double));
    printf("long double is %d bytes\n", (int)sizeof(long double));
    printf("int* is %d bytes\n", (int)sizeof(int*));
    printf("long long* is %d bytes\n", (int)sizeof(long long*));
    printf("float* is %d bytes\n", (int)sizeof(float*));
    printf("double* is %d bytes\n", (int)sizeof(double*));
    return 0;
}