#include <stdio.h>

float Power3(float f) {
    return f * f * f;
}

int main(void) {
    float input;
    printf("Enter a float number:");
    scanf("%f", &input);
    printf("The 3rd power of %.2f is %.2f", input, Power3(input));
    return 0;
}
