#include <stdio.h>

int main(void) {
    int n;
    int i = 1;
    printf("Enter an integer:\n");
    scanf("%d", &n);
    while (i <= 10) {
        printf("%d\n", n + i++);
    }
    return 0;
}
