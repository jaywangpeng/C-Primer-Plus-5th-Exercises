#include <stdio.h>

int main(void) {
    int min, max, temp, result;
    printf("Enter an min and an max integer:");
    while (scanf("%d%d", &min, &max) == 2 && max > min) {
        printf("You have entered min = %d and max = %d\n", min, max);
        result = 0;
        temp = min;
        while (max - temp >= 0) {
            result += temp * temp;
            temp++;
        }
        printf("The sum from square %d to square %d is %d\n", min, max, result);
        printf("Enter an min and an max integer:");
    }
}
