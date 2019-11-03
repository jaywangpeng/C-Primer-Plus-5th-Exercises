#include <stdio.h>

void Temperatures(float Celsius) {
    const float C1 = 1.8;
    const float C2 = 32.0;
    float Fahrenheit, Kelvin;
    Fahrenheit = C1 * Celsius + C2;
    Kelvin = Celsius + 273.16;
    printf("The input temperature is %.2f Celsius or %.2f Kelvin.\n",
            Fahrenheit, Kelvin);
}

int main(void) {
    float Celsius;
    printf("Enter a temperature in Fahrenheit:");
    while (scanf("%f", &Celsius) == 1) {
        Temperatures(Celsius);
        printf("Enter a temperature in Fahrenheit:");
    }
}
