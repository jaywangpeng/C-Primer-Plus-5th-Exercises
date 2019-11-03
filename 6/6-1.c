#include <stdio.h>

int main(void) {
    char alpha[26];
    int i;
    char j = 'a';
    for (i = 0; i < 26; i++, j++) {
        alpha[i] = j;
        printf("%c", alpha[i]);
    }
}
