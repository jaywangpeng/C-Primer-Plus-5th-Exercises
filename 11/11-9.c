#include <stdio.h>
#define MAX 100

void trimspace(char *p1) {
    char s2[MAX];
    char *p2 = s2;
    char *temp = p1;
    while (*p1) {
        if (*p1 != ' ') {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    *p2 = '\0';
    p2 = s2;
    p1 = temp;
    while (*p2) {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
}

int main(void) {
    char s1[MAX];
    puts("Trim the spaces in a string. y to continue. q to exit.");
    while (getchar() != 'q') {
        while (getchar() != '\n')
            continue;
        puts("Enter string:");
        gets(s1);
        trimspace(s1);
        puts(s1);
        puts("Trim the spaces in a string. y to continue. q to exit.");
    }
}
