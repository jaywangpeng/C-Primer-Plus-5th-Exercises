#include <stdio.h>

int main(void) {
    const int DAYS = 7;
    int n;
    printf("Enter the days to convert:\n");
    scanf("%d", &n);
    printf("%d days --> %d weeks and %d days", n, n / DAYS, n % DAYS);
    return 0;
}
