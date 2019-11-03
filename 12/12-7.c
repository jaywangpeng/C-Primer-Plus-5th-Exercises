#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12-7.h"

int main(void)
{
    int roll[100];
    int i, sets, dice, sides;
    char ch;

    srand((unsigned int) time(0));
    puts("Enter the number of sets: (max 100) enter q to stop.");
    while (scanf("%d", &sets) == 1) {
        if (scanf("%c", &ch) == 1 && ch == 'q')
            break;
        if (sets > 100) {
            puts("maximum sets are 100");
            continue;
        }
        puts("How many sides and how many dice?");
        scanf("%d%d", &sides, &dice);
        for (i = 0; i < sets; i++)
            roll[i] = roll_n_dice(dice, sides);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (i = 0; i < sets; i++)
            printf("%d ", roll[i]);
        puts("\nHow many sets? Enter q to stop.");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}
