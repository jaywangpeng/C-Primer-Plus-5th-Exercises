#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *src;
    FILE *dst;
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
    if ((src = fopen(argv[1], "rb")) == NULL) {
        puts("Can't open source file");
        exit(EXIT_FAILURE);
    }
    if ((dst = fopen(argv[2], "wb")) == NULL) {
        puts("Destination file already exists. Use a different name.");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(src)) != EOF)
        putc(ch, dst);
    fclose(src);
    fclose(dst);
    return 0;
}
