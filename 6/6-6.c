#include <stdio.h>
#include <string.h>
#define MAX 20

int main(void) {
    char word[MAX];
    int i;
    printf("Enter a word:");
    if (scanf("%s", word) == 1) {
        printf("Reverted your word:");
        for (i = strlen(word); i >= 0; i--) {
            printf("%c", word[i]);
        }
    }
}
