#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main(void) {
    FILE *fp;
    char words[MAX];
    char new_words[MAX + 1];
    int n = 1;

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stdout,"Can't open \"words\" file.\n");
        exit(1);
    }
    puts("Enter words to add to the file; press the Enter");
    puts("key at the beginning of a line to terminate.");
    while (gets(words) != 0 && words[0] != '\0') {
        fprintf(fp, "%d:", n);
        fprintf(fp, "%s ", words);
        n++;
    }
    puts("File contents:");
    rewind(fp);
    n = 1;
    while (fscanf(fp, "%s", words) == 1) {
        puts(words);
        n++;
    }
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return 0;
}
