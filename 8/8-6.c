#include <stdio.h>

char get_first(void) {
    int ch;
    while ((ch = getchar()) == ' ' || ch == '\t')
        ;
    return ch;
}

int main(void) {
    printf("Enter some words:\n");
    printf("The first non-blank character is %c\n", get_first());
}
