#include <stdio.h>

// Use linear search
int peak_find(int array[], int n) {
    int peak = array[0];
    while (n > 0) {
        if (array[n - 1] > peak)
            peak = array[n - 1];
        n--;
    }
    return peak;
}

void print_array(int array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void) {
    int a[5] = {3, 34, 51, 29, 18};
    print_array(a, 5);
    printf("Peak integer is %d\n", peak_find(a, 5));
    return 0;
}
