#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch[9];
    int i, result;
    puts("Convert number string to base 10 integers:");
    gets(ch);
    for (i = 0, result = 0; isdigit(ch[i]) && ch[i] != '\0'; ++i) {
        result = result * 10 + ch[i] - '0';
    }
    printf("%d", result);
}
