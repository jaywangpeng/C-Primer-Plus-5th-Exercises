#include <stdio.h>
#include <stdlib.h>

void count(char ch, char *file) {
    FILE *fp;
    int n = 0;
    int c;
    if ((fp = fopen(file, "r")) == NULL)
        fprintf(stderr, "Cannot open file %s\n", file);
    else {
        while ((c = getc(fp)) != EOF)
            if (c == ch)
                n++;
        fclose(fp);
        printf("Count of %c in %s is %d\n", ch, file, n);
    }
}

int main(int argc, char *argv[]) {
    char names[10][100];
    int i, j;

    if (argc < 2) {
        puts("Usage: 13-8.exe <character> <file1> <file2> ... (max 10 files)");
        exit(EXIT_FAILURE);
    }
    else if (argc == 2) {
        for (i = 0; i < 10; i++) {
            puts("Enter the file names: (blank line to finish)");
            gets(names[i]);
            if (names[i][0] == '\0')
                break;
        }
        for (j = 0; j < i; j++) {
            count(*argv[1], names[j]);
        }
    }
    else
        for (i = 2; i < 12; i++)
            count(*argv[1], argv[i]);
    return 0;
}
