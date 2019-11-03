#include <stdio.h>
#define MAX 100

int main(void) {
    int count=0;
    char ch;
    while ((ch = getchar()) != EOF && count < 100) {
        printf("%c", ch);
        count++;
    }
    printf("\nThe count of entered charactors is:%d", count - 1);
}
