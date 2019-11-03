#include <stdio.h>

char *chsearch(char *p, char ch) {
    char *r;
    r = NULL;
    while (*p) {
        if (*p == ch) {
            r = p;
        }
        p++;
    }
    return r;
}

int main(void) {
    char words[100];
    char ch;
    char *p;
    puts("Enter some words. (max 100 characters)");
    while (1) {
        gets(words);
        puts("Enter a character to search in these words.");
        ch = getchar();
        p = chsearch(words, ch);
        if (p == NULL)
            printf("Not found: %c\n", ch);
        else
            printf("Search result:\nwords[%d] = %c\n", p - words, *p);
        puts("Enter some words. (max 100 characters)");
    }
    return 0;
}
