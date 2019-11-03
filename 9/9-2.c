#include <stdio.h>

void chline(char ch, int i, int j) {
    int p;
    if (i > 0 && j < 100 && i < j) {
        for (p = 0; p < j; p++) {
            if (p < i)
                putchar(' ');
            if (p >= i && p <= j)
                putchar(ch);
        }
    }
    else {
        printf("Input must be between 0 and 100\n");
    }
}

int main(void) {
    char ch;
    int i, j;
    printf("Enter the char:\n");
    scanf("%c", &ch);
    printf("Enter starting column:\n");
    scanf("%d", &i);
    printf("Enter ending column:\n");
    scanf("%d", &j);
    chline(ch, i, j);
}
