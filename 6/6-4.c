#include <stdio.h>

int main(void) {
    int i, j, k, l;
    char ch;
    printf("Enter a charactor:");
    if (scanf("%c", &ch) == 1) {
        for (i = 0; i < 5; i++) {
            for (j = 5; j > i; j--) {
                printf(" ");
            }
            for (k = 0; k <= i; k++) {
                printf("%c", ch + k);
            }
            for (l = 1; l <= i; l++) {
                printf("%c", ch + k - l - 1);
            }
            printf("\n");
        }
    }
    else {
        printf("Wrong input\n");
    }
    return 0;
}
