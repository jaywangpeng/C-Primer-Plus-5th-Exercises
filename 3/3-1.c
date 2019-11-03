#include <stdio.h>

int main(void) {
    int a;
    printf("Please enter an integer (q to exit):\n");
    scanf("%d", &a);
    printf("You have entered %d\n", a);

    float b;
    printf("Please enter a float (q to exit):\n");
    scanf("%f", &b);
    printf("You have entered %f\n", b);

    return 0;
}
