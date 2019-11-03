#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in, *out;
    int array[20][31];
    char ch[10] = ")!@#$%^&*(";
    int i, j;

    if (argc != 3) {
        fprintf(stderr, "Usage: 13-12.exe <inputfile> <outputfile>");
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 20; i++)
        for (j = 0; j < 30; j++)
            fscanf(in, "%d", &array[i][j]);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            putc(ch[array[i][j]], out);
        putc('\n', out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
