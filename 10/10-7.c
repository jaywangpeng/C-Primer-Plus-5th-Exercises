#include <stdio.h>

void copy_ptr(const double *src, double *dst, int n) {
    while (n > 0) {
        *(dst + n - 1) = *(src + n - 1);
        n--;
    }
}

void print_array(double array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%.1f ", array[i]);
    printf("\n");
}

int main(void) {
    double src[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double dst[3];
    double *p1 = src;
    double *p2 = dst;

    printf("source array:\n");
    print_array(src, 7);

    printf("destination array:\n");
    copy_ptr(p1 + 2, p2, 3);
    print_array(dst, 3);

    return 0;
}
