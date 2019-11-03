#include <stdio.h>

void fib(int n) {
    long a, b, c;

    if (n == 1) {
        printf("0\n");
    }
    else if (n == 2) {
        printf("0, 1\n");
    }
    else if (n == 3) {
        printf("0, 1, 1\n");
    }
    else {
        printf("0, 1, 1");
        a = b = c = 1;
        while (n > 3) {
            n--;
            a = b;
            b = c;
            c = a + b;
            printf(", %lu", c);
        }
    }
}

int main(void) {
    int n;

    printf("Enter the length of Fibonacci sequence:\n");
    if (scanf("%d", &n) == 1)
        fib(n);
    else
        printf("Invalid number. Must be a positive integer\n");
    return 0;
}
