#include <stdio.h>

char ischar(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return ch;
    }
    else {
        return -1;
    }
}

int main(void) {
    char ch;
    printf("Enter a charactor: (Ctrl+Z to exit)\n");
    while ((ch = getchar()) != EOF) {
        if (ch == '\n')
            continue;
        if (ischar(ch) == -1) {
            printf("%c is not a character\n", ch);
        }
        else {
            printf("The character %c ASCII is %d\n", ch, ch);
        }
        printf("Enter a charactor: (Ctrl+Z to exit)\n");
    }
}
