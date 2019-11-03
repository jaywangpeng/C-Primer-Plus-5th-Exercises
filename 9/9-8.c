#include <stdio.h>

double recurse(double n, int p) {
    double r = 1;
    if (n == 0) {
        r = 0;
    }
    else if (n == 1) {
        r = 1;
    }
    else if (p > 0) {
        r = recurse(n, p - 1) * n;
        printf("n = %lf, p = %d, r = %lf\n", n, p, r);
    }
    else if (p < 0) {
        r = recurse(n, p + 1) / n;
        printf("n = %lf, p = %d, r = %lf\n", n, p, r);
    }
    return r;
}

int main(void) {
    double n;
    int p;

    printf("Enter a number:\n");
    if (scanf("%lf", &n) == 1) {
        printf("Enter an exponent of this number:\n");
        if (scanf("%d", &p) == 1) {
            printf("The exponent %d of number %lf is %lf\n", 
                    p, n, recurse(n, p));
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
