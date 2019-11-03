#include <stdio.h>
#define WATER 3.0e-023

int main(void) {
    float quart;
    printf("Enter how much quart of water:\n");
    scanf("%f", &quart);
    printf("There are %.2e molecules in %.2f quarts of water.\n",
            quart * 950 / WATER, quart);
    return 0;
}
