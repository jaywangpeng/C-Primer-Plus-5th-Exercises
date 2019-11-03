#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int array[MAX];

void gen(int arr[], int n) {
    int i, m;
    for (i = 0; i < n; i++) {
        m = rand() % 10;
        if (m == 0)
            arr[i] = 10;
        else
            arr[i] = m;
    }
}

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < MAX; i++)
        for (j = i + 1; j < MAX; j++)
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void) {
    srand((unsigned int) time(0));
    puts("Generating 100 integers...");
    gen(array, MAX);
    display(array, MAX);
    puts("\nSorted them:");
    sort(array, MAX);
    display(array, MAX);
}
