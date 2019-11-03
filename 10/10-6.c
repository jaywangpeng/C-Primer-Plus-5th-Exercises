#include <stdio.h>

#define YEARS 5
#define MONTHS 12

void copy_ptr(float src[], float dst[], int n) {
    while (n > 0) {
        dst[n - 1] = src[n - 1];
        n--;
    }
}

void print_array(float array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%.1f\t", array[i]);
    printf("\n");
}

int main(void) {
    float src[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    float dst[YEARS][MONTHS];
    int i;

    printf("Source Matrix:\n");
    for (i = 0; i < YEARS; i++)
        print_array(src[i], MONTHS);

    for (i = 0; i < YEARS; i++)
        copy_ptr(src[i], dst[i], MONTHS);

    printf("Copied Matrix:\n");
    for (i = 0; i < YEARS; i++)
        print_array(dst[i], MONTHS);

    return 0;
}
