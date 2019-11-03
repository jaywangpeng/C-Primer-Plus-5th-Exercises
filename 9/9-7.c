#include <stdio.h>

double power(double n, int p) {
    double pow = 1;
    int i;

    if (n == 0) {
        pow = 0;
    }
    else if (n == 1 || p == 0) {
        pow = 1;
    }
    else if (p > 0) {
        for (i = 0; i < p; i++) {
            pow *= n;
        }
    }
    else if (p < 0) {
        for (i = 0; i > p; i--) {
            pow /= n;
        }
    }
    return pow;
}

int main(void) {
    double n;
    int p;

    printf("Enter a number:\n");
    if (scanf("%lf", &n) == 1) {
        printf("Enter an exponent of this number:\n");
        if (scanf("%d", &p) == 1) {
            printf("The exponent %d of number %lf is %lf\n", p, n, power(n, p));
        }
        else {
            printf("Invalid exponent\n");
        }
    }
    else {
        printf("Invalid number\n");
    }
    return 0;
}
