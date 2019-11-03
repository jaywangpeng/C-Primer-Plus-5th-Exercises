#include <stdio.h>
#include <stdlib.h>

int gets(char *);

int main(void) {
    int ch;
    FILE *fp;
    long count = 0;
    char name[100];
    puts("Enter the file name. Must be in the same folder of this program");
    puts("or the full path of the file");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL) {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", name, count);
}
