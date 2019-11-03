#include <stdio.h>

int main(void) {
    char firstname[20], lastname[20];
    printf("What is your first name:\n");
    scanf("%s", firstname);
    printf("What is your last name:\n");
    scanf("%s", lastname);
    printf("Your name is %s, %s\n", firstname, lastname);
    return 0;
}
