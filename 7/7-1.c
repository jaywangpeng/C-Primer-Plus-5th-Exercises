#include <stdio.h>

int main(void) {
    char ch[100];
    int space = 0, cr = 0, chars = 0, i = 0, j = 0;
    printf("Enter some charactors:");
    while (1) {
        scanf("%c", &ch[j]);
        if (ch[j] == '#') break;
        j++;
    }
    for (i = 0; i <= j; i++) {
        switch (ch[i]) {
            case ' '  : space++; break;
            case '\n' : cr++; break;
            default   : chars++; break;
        }
    }
    printf("Count of spaces: %d\n", space);
    printf("Count of CR: %d\n", cr);
    printf("Count of characters: %d\n", chars-1);
}
