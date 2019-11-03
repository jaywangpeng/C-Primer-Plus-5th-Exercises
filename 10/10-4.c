#include <stdio.h>

// Use linear search
int peak_index(double array[], int n) {
    int i = 0;
    double peak = array[0];
    while (n > 0) {
        if (array[n - 1] > peak) {
            peak = array[n - 1];
            i = n - 1;
        }
        n--;
    }
    return i;
}

void print_array(double array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("[%d] %.2f\n", i, array[i]);
    printf("\n");
}

int main(void) {
    double a[5] = {3.4, 1.34, 5.1, 2.9, 3.18};
    print_array(a, 5);
    printf("Peak index is %d\n", peak_index(a, 5));
    return 0;
}
