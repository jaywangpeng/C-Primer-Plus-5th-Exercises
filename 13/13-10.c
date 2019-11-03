#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char name[100];
    char ch;
    long n;
    long length;

    puts("Enter the text file name to open:");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", name);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    length = ftell(fp) - 1;
    rewind(fp);
    puts("Enter the number of characters you want to skip");
    puts("I will print out the remaining till the end of line");
    printf("File length is %ld\n", length);
    while (scanf("%ld", &n) == 1) {
        if (n <= length) {
            fseek(fp, n, SEEK_SET);
            while ((ch = getc(fp)) != '\n')
                putchar(ch);
            rewind(fp);
            puts("\nEnter the number of characters you want to skip");
        }
        else
            printf("%ld is exceeding the file length. Try again.\n", n);
    }
    fclose(fp);
    return 0;
}
