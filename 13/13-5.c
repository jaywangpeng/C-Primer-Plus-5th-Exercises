#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

void append(FILE *source, FILE *dest) {
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once

    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}

int main(int argc, char *argv[]) {
    FILE *fa, *fs;
    int i;

    if (argc < 3) {
        puts("Usage: 13-5.exe <append_to_file> <file1> <file2>");
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "a")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (i = 2; i < argc; i++) {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else {
            if ((fs = fopen(argv[i], "r")) == NULL) {
                fprintf(stderr, "Can't open %s\n", argv[i]);
                continue;
            }
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr,"Error in reading file %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr,"Error in writing file %s.\n", argv[1]);
            fclose(fs);
            printf("File %s is appended to %s\n", argv[i], argv[1]);
        }
    }
    fclose(fa);
    return 0;
}
