#include <stdio.h>
#define RATE 2.54

int main(void) {
    float height, inch;
    int feet;
    printf("Enter a height in centimeters:");
    while (scanf("%f", &height) == 1 && height > 0) {
        inch = height / RATE;
        feet = (int)(inch / 12.0);
        printf("%.2f cm = %d feet, %.2f inches\n",
                height, feet, inch - feet * 12);
        printf("Enter a height in centimeters:");
    }
    return 0;
}
