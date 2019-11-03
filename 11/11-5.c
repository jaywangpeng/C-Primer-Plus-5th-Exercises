#include <stdio.h>

int is_within(char ch, char *p) {
    while (*p) {
        if (*p++ == ch)
            return 1;
    }
    return 0;
}

int main(void) {
    char words[100];
    char ch;
    puts("Enter some words. (max 100 characters)");
    while (1) {
        gets(words);
        puts("Enter a character to search in these words.");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        if (is_within(ch, words))
            printf("Found it: %c\n", ch);
        else
            printf("Not found: %c\n", ch);
        puts("Enter some words. (max 100 characters)");
    }
    return 0;
}
