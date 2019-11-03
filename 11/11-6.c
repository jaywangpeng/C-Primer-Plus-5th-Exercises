#include <stdio.h>

char *strncopy(char *s1, char *s2, int n) {
    if (strlen(s2) >= n) {
        *(s2 + n) = '\0';
        *(s1 + n) = '\0';
        printf("if\ts2 length = %d; n = %d\n", strlen(s2), n);
    }
    else {
        n = strlen(s2);
        *(s1 + n) = '\0';
        printf("else\ts2 length = %d; n = %d\n", strlen(s2), n);
    }
    while (n >= 0) {
        *(s1 + n - 1) = *(s2 + n - 1);
        n--;
    }
    return s1;
}

int main(void) {
    int n;
    char ch1[100], ch2[100];
    puts("Enter some words. I will copy it to another array.");
    gets(ch2);
    puts("How many characters to copy?");
    scanf("%d", &n);
    puts("Copied to:");
    puts(strncopy(ch1, ch2, n));
    return 0;
}
