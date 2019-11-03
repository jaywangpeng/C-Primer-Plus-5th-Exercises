#include <stdio.h>

int main(void) {
    int n;
    int min, max;
    printf("Enter a range of integer.\nMIN = ");
    scanf("%d", &min);
    printf("MAX = ");
    scanf("%d", &max);
    if (min >= 0 && max <= 100) {
        printf("The result is:\n%5cInput%4cSquare%4cPower3\n", ' ', ' ', ' ');
        for (n = min; n <= max; n++) {
            printf("%10d", n);
            printf("%10d", n * n);
            printf("%10d\n", n * n * n);
        }
    }
    else {
        printf("Wrong input");
    }
    return 0;
}
