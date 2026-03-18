#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    float c_input, f_result;

    printf("Enter temperature in Celsius:\n");
    scanf("%f", &c_input);

    f_result = celsiusToFahrenheit(c_input);

    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", c_input, f_result);

    return 0;
}