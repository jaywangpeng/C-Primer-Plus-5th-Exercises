#include <stdio.h>

int main(void) {
    float a, b;
    printf("Enter two float numbers, use space in between:");
    while (scanf("%f", &a) == 1 && scanf("%f", &b) == 1) {
        printf("(a - b) / (a * b) = %f\n", (a - b) / (a * b));
        printf("Enter two float numbers, use space in between:");
    }
}
