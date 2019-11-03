#include <stdio.h>

void copy_arr(const double src[], double dst[], int n) {
    while (n > 0) {
        dst[n - 1] = src[n - 1];
        n--;
    }
}

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
    int i;
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];

    printf("source array:  ");
    print_array(source, 5);

    printf("target1 array: ");
    copy_arr(source, target1, 5);
    print_array(target1, 5);

    printf("target2 array: ");
    copy_ptr(source, target2, 5);
    print_array(target2, 5);

    return 0;
}
