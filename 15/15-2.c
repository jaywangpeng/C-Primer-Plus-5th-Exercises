#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strtodec(char *ch) {
    int count;
    int result = 0;
    int i;
    count = strlen(ch);
    for (i = 0; i < count; i++)
        if (*(ch + i) == '1')
            result += 1<<(count - 1 - i);
    return result;
}

char *dectobinstr(int n, char *ch) {
    int i;
    int size = 8 * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ch[i] = (n & 1) + '0';
    ch[size] = '\0';
    return ch;
}

int main(int argc, char *argv[]) {
    int a1, a2;
    char *str;
    if (argc != 3) {
        fprintf(stderr, "Usage: 15-2.exe <binary1> <binary2>");
        return -1;
    }
    str = (char *)malloc(8 * sizeof(int) + 1);
    a1 = strtodec(argv[1]);
    a2 = strtodec(argv[2]);
    printf("~ %s = %s\n", argv[1], dectobinstr(~ a1, str));
    printf("~ %s = %s\n", argv[2], dectobinstr(~ a2, str));
    printf("& = %s\n", dectobinstr(a1 & a2, str));
    printf("| = %s\n", dectobinstr(a1 | a2, str));
    printf("^ = %s\n", dectobinstr(a1 ^ a2, str));
    free(str);
    return 0;
}
