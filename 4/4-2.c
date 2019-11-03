#include <stdio.h>

int main(void){
    char firstname[10], lastname[10];
    printf("What is your name?\n");
    scanf("%s%s", firstname, lastname);
    printf("\"%s %s\"\n", firstname, lastname);
    printf("\"%10s %10s\"\n", firstname, lastname);
    printf("\"%-10s %-10s\"\n", firstname, lastname);
    printf("%s %s\n", firstname, lastname);
    return 0;
}
