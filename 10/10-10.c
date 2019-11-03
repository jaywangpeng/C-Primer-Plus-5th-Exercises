#include <stdio.h>

#define M 3
#define N 5

void print_array(float a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%.1f ", a[i]);
    printf("\n");
}

void double_array(float a[], int n) {
    while (n > 0) {
        a[n - 1] *= 2.0;
        n--;
    }
}

int main(void) {
    float array[M][N] = {
        {4.3,4.3,4.3,3.0,2.0},
        {8.5,8.2,1.2,1.6,2.4},
        {9.1,8.5,6.7,4.3,2.1}
    };
    int i;

    printf("Original array:\n");
    for (i = 0; i < M; i++)
        print_array(array[i], N);

    for (i = 0; i < M; i++)
        double_array(array[i], N);

    printf("Doubled array:\n");
    for (i = 0; i < M; i++)
        print_array(array[i], N);
}
