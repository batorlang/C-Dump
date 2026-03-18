#include <stdio.h>
#include <complex.h>

void ComplexToMatrix(const double complex z, double Matrix[2][2]);
void MatMul(const double Mat1[2][2], const double Mat2[2][2], double ResMat[2][2]);

int main() {
    double a1, b1, a2, b2;
    double mat1[2][2], mat2[2][2], res[2][2];

    printf("First complex number: ");
    if (scanf("%lf + %lfi", &a1, &b1) != 2) {
    }

    printf("Second complex number: ");
    scanf("%lf + %lfi", &a2, &b2);

    ComplexToMatrix(a1 + b1 * I, mat1);
    ComplexToMatrix(a2 + b2 * I, mat2);

    MatMul(mat1, mat2, res);

    printf("[ %f %f ]\n", res[0][0], res[0][1]);
    printf("[ %f %f ]\n", res[1][0], res[1][1]);

    return 0;
}