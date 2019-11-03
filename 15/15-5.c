#include <stdio.h>
#include <stdlib.h>

unsigned int rotate_l(unsigned int n, int m) {
    int size = 8 * sizeof(int);
    unsigned int temp;
    m %= size;
    temp = n >> (size - m);
    return (n << m) | temp;
}

char *dectobinstr(unsigned int n, char *ch) {
    int i;
    int size = 8 * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ch[i] = (n & 1) + '0';
    ch[size] = '\0';
    return ch;
}

int main(void) {
    char *str;
    unsigned int n, r;
    int m;
    str = (char *)malloc(8 * sizeof(int) + 1);
    puts("Enter an integer");
    scanf("%d", &n);
    puts("Enter how many bits to rotate to left");
    scanf("%d", &m);
    r = rotate_l(n, m);
    printf("Decimal:  %u\n", r);
    printf("Original: %s\n", dectobinstr(n, str));
    printf("Rotated:  %s\n", dectobinstr(r, str));
    free(str);
    return 0;
}
