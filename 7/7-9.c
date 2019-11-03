#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; (i * i) <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n, i;
    printf("Enter an integer: ");
    if (scanf("%d", &n) == 1) {
        for (i = 1; i <= n; i++) {
            if (is_prime(i)) {
                printf("Prime number: %d\n", i);
            }
        }
    }
    else {
        printf("Wrong input.");
    }
    return 0;
}
