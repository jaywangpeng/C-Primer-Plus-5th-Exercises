#include <stdio.h>

void add_array(int a[], int b[], int c[], int n) {
    int i;
    for (i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}

void print_array(int array[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void) {
    int array1[4] = {2, 4, 5, 8};
    int array2[4] = {1, 0, 4, 6};
    int array3[4];

    print_array(array1, 4);
    print_array(array2, 4);
    printf("Add them up:\n");
    add_array(array1, array2, array3, 4);
    print_array(array3, 4);
}
