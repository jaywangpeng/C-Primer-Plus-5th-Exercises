#include <stdio.h>

int main(void) {
    int ascii;
    printf("Please enter a ASCII code(0 - 127):\n");
    scanf("%d", &ascii);
    if (ascii >= 0 && ascii <= 127) {
        printf("It equals ASCII char: '%c'\n", ascii);
    }
    else {
        printf("Your input is out of range.\n");
    }
    return 0;
}
