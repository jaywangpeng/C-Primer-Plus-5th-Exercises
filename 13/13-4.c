#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int i, ch;

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) != NULL) {
            printf("Content of file %s\n", argv[i]);
            while ((ch = getc(fp)) != EOF)
                putchar(ch);
            fclose(fp);
        }
        else
            printf("Cannot open file %s\n", argv[i]);
        putchar('\n');
    }
    return 0;
}
