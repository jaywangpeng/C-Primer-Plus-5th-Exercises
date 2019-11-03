#include <stdio.h>
#include <stdlib.h>

int openbits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
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
    int n;
    char *str;
    str = (char *)malloc(8 * sizeof(int) + 1);
    puts("Enter an integer");
    if (scanf("%d", &n) == 1) {
        puts(dectobinstr(n, str));
        printf("Count of open bits is %d\n", openbits(n));
    }
    else
        puts("Invalid input");
    free(str);
    return 0;
}
