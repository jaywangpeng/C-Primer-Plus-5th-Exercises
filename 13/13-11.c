#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAXLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: 13-11.exe <string> <filename>\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAXLEN, fp) != NULL) {
        if ((strstr(line, argv[1])) != NULL) {
            fputs(line, stdout);
        }
    }
    fclose(fp);
    return 0;
}
