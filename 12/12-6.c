#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int array[MAX];

void gen(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 10 + 1;
}

int count(int arr[], int n, int target) {
    int i, count;
    for (i = 0, count = 0; i < n; i++)
        if (arr[i] == target)
            count++;
    return count;
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void) {
    int i;
    int targets[10];

    srand((unsigned int) time(0));
    puts("Generating 100 integers...");
    gen(array, MAX);
    display(array, MAX);
    puts("\nCounts from 1 to 10:");
    for (i = 1; i < 11; i++) {
        targets[i - 1] = count(array, MAX, i);
        printf("%d: %d\n", i, targets[i - 1]);
    }
}
