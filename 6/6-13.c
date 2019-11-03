#include <stdio.h>

int main(void) {
    double a[8], b[8];
    int i;
    printf("Enter 8 float numbers, use space in between:");
    for (i = 0; i < 8; i++) {
        scanf("%lf", &a[i]);
    }
    b[0] = a[0];
    for (i = 1; i < 8; i++) {
        b[i] = a[i] + b[i - 1];
    }
    printf("The array is\n");
    for (i = 0; i < 8; i++) {
        printf("%lf ", a[i]);
    }
    printf("\nSum of previous array is\n");
    for (i = 0; i < 8; i++) {
        printf("%lf ", b[i]);
    }
}
