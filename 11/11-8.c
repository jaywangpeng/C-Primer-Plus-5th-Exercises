#include <stdio.h>

void revert(char *ch) {
    int i, j, len;
    char temp;
    len = strlen(ch);
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = *(ch + i);
        *(ch + i) = *(ch + j);
        *(ch + j) = temp;
    }
}

int main(void) {
    char s1[100];
    puts("Revert the string. y to continue. q to exit.");
    while (getchar() != 'q') {
        while (getchar() != '\n')
            continue;
        puts("Enter string:");
        gets(s1);
        revert(s1);
        puts(s1);
        puts("Revert the string. y to continue. q to exit.");
    }
}
