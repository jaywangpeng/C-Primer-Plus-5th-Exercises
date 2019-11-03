#include <stdio.h>

int main(void){
    float a;
    printf("Enter a float number:\n");
    scanf("%f", &a);
    printf("The input is %.2f or %e\n", a, a);
    return 0;
}
