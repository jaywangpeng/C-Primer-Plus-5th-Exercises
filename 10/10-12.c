#include <stdio.h>

#define M 3
#define N 5

double row_avg(const double a[], int n) {
    double total = 0;
    int i;
    for (i = 0; i < n; i++)
        total += a[i];
    return total / n;
}

double avg(const double a[][N], int m) {
    double total = 0;
    int i;
    for (i = 0; i < m; i++)
        total += row_avg(a[i], N);
    return total / (m * N);
}

double peak(const double a[][N], int m) {
    double peak = a[0][0];
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < N; j++) {
            if (peak < a[i][j])
                peak = a[i][j];
        }
    }
    return peak;
}

void print_array(const double array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%6.2lf   ", array[i]);
    printf("\n");
}

void fill_array(double array[], int n) {
    int i;
    double number;
    for (i = 0; i < n; i++) {
        while (scanf("%lf", &array[i]) != 1) {
            continue;
        }
    }
}

int main(void) {
    double array[M][N];
    int i;

    printf("Fill the 2D array with numbers:\n");
    for (i = 0; i < M; i++) {
        printf("Row %d:\n", i + 1);
        fill_array(array[i], N);
    }

    printf("\nThis is the array you have entered:\n");
    for (i = 0; i < M; i++)
        print_array(array[i], N);

    printf("\nAverages of each row are:\n");
    for (i = 0; i < M; i++) {
        printf("Row %d: %.2lf\n", i, row_avg(array[i], N));
    }

    printf("\nOverall average is: %.2lf\n", avg(array, M));
    printf("\nPeak number is: %.2lf\n", peak(array, M));

    return 0;
}
