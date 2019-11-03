#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1001

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    int c;

    if (argc != 3) {
        puts("Usage: 13-7.exe <file1> <file2>");
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (1) {
        while ((c = getc(fp1)) != '\n' && c != EOF)
            putc(c, stdout);
        while ((c = getc(fp2)) != '\n' && c != EOF)
            putc(c, stdout);
        putc('\n', stdout);
        if (c == EOF)
            break;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
