#include <stdio.h>
#include <stdlib.h>

int flatten_peak(const int i, const int j, const int array[20][31]) {
    int self = array[i][j];
    int left, right, above, below, n;
    n = 1;
    left = right = above = below = 0;
    if (j - 1 >= 0 && self - array[i][j - 1] > 1) {
        left = array[i][j - 1];
        n++;
    }
    if (j + 1 <= 29 && self - array[i][j + 1] > 1) {
        right = array[i][j + 1];
        n++;
    }
    if (i - 1 >= 0 && self - array[i - 1][j] > 1) {
        above = array[i - 1][j];
        n++;
    }
    if (i + 1 <= 19 && self - array[i + 1][j] > 1) {
        below = array[i + 1][j];
        n++;
    }
    return (left + right + above + below + self) / n;
}

int main(int argc, char *argv[]) {
    FILE *in, *out;
    int array[20][31];
    char ch[10] = ")!@#$%^&*(";
    int i, j;

    if (argc != 3) {
        fprintf(stderr, "Usage: 13-13.exe <inputfile> <outputfile>");
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
    for (i = 0; i < 20; i++)
        for (j = 0; j < 30; j++)
            array[i][j] = flatten_peak(i, j, array);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            putc(ch[array[i][j]], out);
        putc('\n', out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
