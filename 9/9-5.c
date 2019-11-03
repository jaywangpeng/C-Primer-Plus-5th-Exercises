#include <stdio.h>

void larger_of(double *x, double *y) {
    if (*x > *y) {
        *y = *x;
    }
    else {
        *x = *y;
    }
}

int main(void) {
    double a, b;
    printf("Enter the first number:\n");
    scanf("%lf", &a);
    printf("Enter the second number:\n");
    scanf("%lf", &b);
    larger_of(&a, &b);
    printf("a = %lf\n", a);
    printf("b = %lf\n", b);
}
