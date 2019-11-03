#include <stdio.h>
#define MAX 8

int main(void) {
    int a[MAX], i;
    printf("Enter %d integers:", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &a[i]);
    for (i = MAX - 1; i >= 0; i--)
        printf("%d ", a[i]);
}
