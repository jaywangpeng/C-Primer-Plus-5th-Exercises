#include <stdio.h>
#define SecOfYear 31560000

int main(void) {
    int age;
    printf("Please enter your age:\n");
    scanf("%d", &age);
    if (age > 0 && age < 120) {
        printf("Your age is %u seconds", age * SecOfYear);
    }
    return 0;
}
