#include <stdio.h>

int main(void) {
    int ch;
    printf("Enter ASCII characters which will be printed as:\nChar -> Decimal;\n");
    while ((ch = getchar()) != EOF) {
        if (ch == ' ')
            printf("space\t%d\n", ch);
        else if (ch == '\n')
            printf("newline\t%d\n", ch);
        else if (ch == '\t')
            printf("tab\t%d\n", ch);
        else if (ch < ' ')
            printf("%c\t^%c\n", ch, ch + 64);
        else {
            printf("%c\t%d\n", ch, ch);
        }
    }
}
