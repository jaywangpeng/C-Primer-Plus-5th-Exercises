#include <stdio.h>

// Use linear search
void max_min_diff(const double array[], int n) {
    double min, max;
    min = max = array[0];
    while (n > 0) {
        if (array[n - 1] > max)
            max = array[n - 1];
        else if (array[n - 1] < min)
            min = array[n - 1];
        n--;
    }
    printf("Max - Min = Difference\n");
    printf("%.2f - %.2f = %.2f\n", max, min, max - min);
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
    max_min_diff(a, 5);
    return 0;
}
