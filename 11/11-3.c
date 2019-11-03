#include <stdio.h>

void save_word(char *p) {
    char ch;
    while ((ch = getchar()) != '\t' && ch != ' ' && ch != '\n') {
        *p = ch;
        p++;
    }
}

int main(void) {
    char word[30];
    printf("Enter some words. I will save the first one.\n");
    save_word(word);
    printf("Here is the saved word(length is %d)\n", strlen(word));
    puts(word);
}
