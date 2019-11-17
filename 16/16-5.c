#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 10

void prnt_nums(int array[], int n, int count) {
    int i;
    srand((unsigned int)time(0));
    while (count--) {
        i = rand() % n;
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int main(void) {
    int count, i;
    int array[MAXLEN] = { 0,1,2,3,4,5,6,7,8,9 };
    puts("Original array:");
    for (i = 0; i < MAXLEN; i++)
        printf("%d ", array[i]);
    putchar('\n');
    puts("Enter how many numbers to print:");
    scanf("%d", &count);
    prnt_nums(array, MAXLEN, count);
    return 0;
}
