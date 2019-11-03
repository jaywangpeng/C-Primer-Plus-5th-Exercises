#include <stdio.h>

double mean(double i, double j) {
    return 1.0 / ((1.0 / i + 1.0 / j) / 2.0);
}

int main(void) {
    double i, j;
    printf("Enter the first number:\n");
    scanf("%lf", &i);
    printf("Enter the second number:\n");
    scanf("%lf", &j);
    printf("mean = %lf\n", mean(i, j));
}
