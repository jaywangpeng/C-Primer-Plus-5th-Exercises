#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    int ch;

    if (argc == 1) {
        puts("Missing source file name");
        exit(EXIT_FAILURE);
    }
    else if (argc == 2) {
        puts("Missing destination file name");
        exit(EXIT_FAILURE);
    }
    else if (argc > 3) {
        puts("Too many arguments");
        exit(EXIT_FAILURE);
    }
    if ((src = fopen(argv[1], "r")) == NULL) {
        puts("Cannot open source file");
        exit(EXIT_FAILURE);
    }
    if ((dst = fopen(argv[2], "w")) == NULL) {
        puts("Cannot open source file");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(src)) != EOF) {
        putc(toupper(ch), dst);
    }
    fclose(src);
    fclose(dst);
    return 0;
}
