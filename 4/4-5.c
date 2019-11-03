#include <stdio.h>
#include <string.h>

int main(void) {
    char firstname[10], lastname[10];
    printf("Enter your first name:\n");
    scanf("%s", firstname);
    printf("Enter your last name:\n");
    scanf("%s", lastname);
    printf("%-10s %-10s\n", firstname, lastname);
    printf("%-10d %-10d\n", strlen(firstname), strlen(lastname));
    return 0;
}
