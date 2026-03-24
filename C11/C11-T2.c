#include <stdio.h>
#include <math.h>

int main() {
    double v, theta; //Inputs
    const double g = 9.8; //preset acc of gravity

    printf("Enter initial speed v (m/s):\n");
    if (scanf("%lf", &v) != 1) { //simple error handling
        return 1;
    }

    printf("Enter launch angle theta (radians):\n");
    if (scanf("%lf", &theta) != 1) {
        return 1;
    }
    double sintheta = sin(theta);
    double maxheight = (v*v*sintheta*sintheta) / (2*g);
    double time = (2*v*sintheta) / g;
    printf("Maximum Height:\n");
    printf("--Exact: %.2f m\n", maxheight);
    printf("--Floor: %.2f m\n", floor(maxheight));
    printf("--Ceil : %.2f m\n", ceil(maxheight));

    printf("\nTotal Flight Time:\n");
    printf("--Exact: %.2f s\n", time);
    printf("--Floor: %.2f s\n", floor(time));
    printf("--Ceil : %.2f s\n", ceil(time));

    return 0;
}