#include <stdio.h>

void get_str(char *p, int n) {
    int i;
    for (i = 0; i < n; i++, p++)
        scanf("%c", p);
    p = p - n + 1;
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
    while ((temp = getchar()) != '\n' || temp == ' ')
        continue;
    printf("Please enter characters:\n");
    get_str(p, n);
    for (i = 0; i < n; i++) {
        printf("ch[%d] = %c\n", i, *(p + i));
    }
}
