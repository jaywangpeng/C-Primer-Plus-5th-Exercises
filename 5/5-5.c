#include <stdio.h>

int main(void) {
    int count = 0;
    int sum = 0;
    int n;
    printf("Enter an integer:");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        return 1;
    }
    while (count++ < n) {
        sum = sum + count;
    }
    printf("sum = %d\n", sum);
    return 0;
}
