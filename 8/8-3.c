#include <stdio.h>

int main(void) {
    int c_upper = 0, c_lower = 0;
    int ch;
    printf("Enter some words, I will count it:\n");
    while ((ch = getchar()) != EOF) {
        if (ch > 64 && ch < 91)
            c_upper++;
        if (ch > 96 && ch < 123)
            c_lower++;
    }
    printf("Uppercase letter count: %d\n", c_upper);
    printf("Lowercase letter count: %d\n", c_lower);
}
