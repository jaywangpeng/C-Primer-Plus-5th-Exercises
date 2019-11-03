#include <stdio.h>

int main(void) {
    const float gallonsrate = 3.785;
    const float milerate = 1.609;
    float miles, gallons, gperm, lperk;
    printf("Enter the miles:\n");
    scanf("%f", &miles);
    printf("Enter the gallons:\n");
    scanf("%f", &gallons);
    gperm = gallons / miles * 100;
    lperk = (gallons * gallonsrate) / (miles * milerate) * 100;
    printf("US: %.2f gallons per 100 mile\n", gperm);
    printf("EU: %.2f litres per 100 kilometers\n", lperk);
    return 0;
}
