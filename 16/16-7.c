#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%-10.1lf", ar[i]);
    putchar('\n');
}

double *new_d_array(int n, ...) {
    double *p;
    int i;
    va_list ap;
    p = (double *)malloc(n * sizeof(double));
    if (p == NULL)
        exit(EXIT_FAILURE);
    va_start(ap, n);
    for (i = 0; i < n; i++)
        *(p + i) = va_arg(ap, double);
    va_end(ap);
    return p;
}

int main(void) {
    double *p1, *p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}
