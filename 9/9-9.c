#include <stdio.h>

void to_base_n(unsigned long n, int b) {
    int r;

    r = n % b;
    if (n >= b) {
        to_base_n(n / b, b);
    }
    putchar('0' + r);
    return;
}

int main(void) {
    unsigned long number;
    int base;

    printf("Enter an integer:\n");
    if (scanf("%lu", &number) == 1) {
        printf("Enter a base for it:\n");
        if (scanf("%d", &base) == 1 && base > 1 && base < 11) {
            printf("Binary equivalent: ");
            to_base_n(number, base);
            putchar('\n');
        }
        else
            printf("Wrong base number. Must between 2 and 10\n");
    }
    else {
        printf("Invalid number\n");
    }
    return 0;
}
