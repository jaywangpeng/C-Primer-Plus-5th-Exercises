#include <stdio.h>
#define INCHTOCM 2.54

int main(void) {
    int cm, inch, feet;
    printf("Enter your height in centimeters:\n");
    scanf("%d", &cm);
    inch = cm / INCHTOCM;
    feet = inch / 12;
    printf("You height is:\n");
    printf("%dcm\n", cm);
    printf("%d\"\n", inch);
    printf("%d'%d\"", feet, inch % 12);
    return 0;
}
