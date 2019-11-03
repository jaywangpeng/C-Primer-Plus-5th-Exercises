#include <stdio.h>

void grid(char ch, unsigned int i, unsigned int j) {
    int pi, pj;
    if (i > 0 && i < 100 && j > 0 && j < 100) {
        for (pi = 0; pi < i; pi++) {
            for (pj = 0; pj < j; pj++) {
                putchar(ch);
            }
            putchar('\n');
        }
    }
    else {
        printf("Input must be between 0 and 100\n");
    }
}

int main(void) {
    char ch;
    unsigned int rows, columns;
    printf("Enter the char:\n");
    scanf("%c", &ch);
    printf("Enter number of rows:\n");
    scanf("%d", &rows);
    printf("Enter number of columns:\n");
    scanf("%d", &columns);
    grid(ch, rows, columns);
}
