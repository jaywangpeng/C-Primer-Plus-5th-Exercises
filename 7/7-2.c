#include <stdio.h>

int main(void) {
    char ch[100];
    int i = 0, j;
    printf("Enter some charactors:");
    while (1) {
        scanf("%c", &ch[i]);
        if (ch[i] == '#') break;
        i++;
    }
    printf("You have entered:\n");
    for (j = 0; j < i; j++) {
        if (j % 8 == 0)
            printf("\n");
        printf("%c %3d ", ch[j], ch[j]);
    }
    return 0;
}
