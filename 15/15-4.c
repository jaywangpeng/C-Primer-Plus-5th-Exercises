#include <stdio.h>
#include <stdlib.h>

int bitisopen(int n, int m) {
    n >>= m - 1;
    if (n & 1)
        return 1;
    else
        return 0;
}

char *dectobinstr(int n, char *ch) {
    int i;
    int size = 8 * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ch[i] = (n & 1) + '0';
    ch[size] = '\0';
    return ch;
}

int main(void) {
    int n, m;
    char *str;
    str = (char *)malloc(8 * sizeof(int) + 1);
    puts("Enter an integer");
    scanf("%d", &n);
    puts("Enter the bit position");
    scanf("%d", &m);
    printf("%s\nbit %d from right is %d",
            dectobinstr(n, str), m, bitisopen(n, m));
    free(str);
    return 0;
}
