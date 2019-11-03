#include <stdio.h>

int main(void) {
    double a = 1.0 / 3.0;
    float b = 1.0 / 3.0;
    printf("Results of 1.0/3.0\n");
    printf("%%.4f: ");
    printf("double = %.4f; float = %.4f\n", a, b);
    printf("%%.12f: ");
    printf("double = %.12f; float = %.12f\n", a, b);
    printf("%%.16f: ");
    printf("double = %.16f; float = %.16f\n", a, b);
    return 0;
}
