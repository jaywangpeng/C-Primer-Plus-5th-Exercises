#include <stdio.h>

int main (void) {
    float length;
    printf("Convert inches to centimeters. Please enter:");
    scanf("%f", &length);
    printf("%.2f inches is %.2fcm\n", length, length * 2.54);
    return 0;
}
