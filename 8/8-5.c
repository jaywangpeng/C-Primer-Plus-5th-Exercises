#include <stdio.h>

int main(void) {
    int n, min = 0, max = 100, guess = 50;

    printf("Pick an integer from %d to %d. I will guess it.\n", min, max);
    printf("Respond with y or n each time. q to exit.\n");
    printf("Enter an integer:\n");
    scanf("%d", &n);
    printf("Is it %d ?\n", guess);
    while (getchar() != 'q') {
        while (getchar() != '\n')
            continue;
        if (n < guess) {
            max = guess;
        }
        else if (n > guess) {
            min = guess;
        }
        else {
            printf("Your input is %d. My guess is %d.\n", n, guess);
            break;
        }
        printf("min = %d, max = %d, guess = %d\n", min, max, guess);
        guess = (min + max) / 2;
        printf("Is it %d ?\n", guess);
    }
    return 0;
}
