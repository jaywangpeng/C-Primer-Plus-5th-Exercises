#include <stdio.h>
#define MAX 255

int main(void) {
    char a[MAX];
    int i = 0;
    printf("Enter a setence and it will be reverted:\n");
    while (scanf("%c", &a[i]) == 1) {
        if (a[i] == '\n') {
            break;
        }
        i++;
    }
    printf("Reverted to:");
    while (i >= 0) {
        printf("%c", a[i]);
        i--;
    }
}
