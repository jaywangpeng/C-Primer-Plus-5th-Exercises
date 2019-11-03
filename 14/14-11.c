#include <stdio.h>
#include <math.h>

#define MAXLEN 4

void transform(const double *src, double *dst, int n, double (*func)(double)) {
    int i;
    for (i = 0; i < n; i++) {
        dst[i] = (*func)(*(src + i));
        printf("src[%d] = %.2lf, dst[%d] = %.2lf, %p\n",
                i, *(src + i), i, *(dst + i), func);
    }
}

double sqrt(double a) {
    return a * a;
}

double half(double a) {
    return a / 2.0;
}

int main(void) {
    double (*p)(double);
    const double a[MAXLEN] = {1.0, 2.0, 3.0, 4.0};
    double b[MAXLEN];

    p = sin;
    puts("sin");
    transform(a, b, MAXLEN, *p);
    p = cos;
    puts("cos");
    transform(a, b, MAXLEN, *p);
    p = sqrt;
    puts("sqrt");
    transform(a, b, MAXLEN, *p);
    p = half;
    puts("half");
    transform(a, b, MAXLEN, *p);
    return 0;
}
