#include <stdio.h>

char *get_str(char *p, int n) {
    int i;
    for (i = 0; i < n; i++, p++) {
        *p = getchar();
        printf("p address:\t%p\n", p);
        printf("p value:\t%c\n", *p);
        if (*p == ' ' || *p == '\n' || *p == '\t')
            break;
    }
    return p--;
}

int main(void) {
    int n = 0;
    int i;
    char temp;
    char ch[100];
    char *p = ch;
    printf("Enter some characters. I will store it.\n");
    printf("How many characters do you want to store?\n");
    scanf("%d", &n);
    printf("You've entered %d characters.\n", n);
    printf("p address:\t%p\n", p);
    printf("ch address:\t%p\n", ch);
    while ((temp = getchar()) != '\n' || temp == ' ')
        continue;
    printf("Please enter characters:\n");
    p = get_str(p, n);
    printf("After function returns:\n");
    printf("p address:\t%p\n", p);
    printf("ch address:\t%p\n", ch);
    for (i = 0; i < (p - ch); i++)
        printf("ch[%d] = %c\n", i, ch[i]);
}
