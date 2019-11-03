#include <stdio.h>

double min(double a, double b) {
    return a < b ? a: b;
}

double getnumber(void) {
    double n;
    while (scanf("%lf", &n) != 1) {
        printf("Only one number is accepted\n");
    }
    return n;
}

int main(void) {
    double a, b;
    printf("Enter the first number:\n");
    a = getnumber();
    printf("a = %lf\n", a);
    printf("Enter the second number:\n");
    b = getnumber();
    printf("b = %lf\n", b);
    printf("Min of a and b is %lf\n", min(a, b));
    return;
}
