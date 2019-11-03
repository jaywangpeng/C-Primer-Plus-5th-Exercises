#include <stdio.h>

int main(void) {
    float a;
    printf("Please enter a float:\n");
    scanf("%f", &a);
    printf("The input is %f or %e\n", a, a);
}
