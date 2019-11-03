#include <stdio.h>

int main(void) {
    char firstname[10], lastname[10];
    float height;
    printf("Enter your name:\n");
    scanf("%s%s", firstname, lastname);
    printf("Enter your height in inches:\n");
    scanf("%f", &height);
    printf("%s %s, you are %.2f feets tall\n", firstname, lastname, height);
    return 0;
}
