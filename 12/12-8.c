#include <stdio.h>
#include "12-8.h"

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void) {
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    while (size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("\nEnter the number of elements (<1 to quit): ");
        scanf("%d", &size);
    }
    printf("Done.\n");
    return 0;
}
