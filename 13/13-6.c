#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void) {
    FILE  *in, *out;
    int ch;
    char filein[LEN], fileout[LEN];
    int count = 0;

    puts("Enter the file name to be compressed:");
    gets(filein);
    if ((in = fopen(filein, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", filein);
        exit(EXIT_FAILURE);
    }
    strncpy(fileout, filein, LEN - 5);
    fileout[LEN - 5] = '\0';
    strcat(fileout, ".red");
    if ((out = fopen(fileout, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    return 0;
}
