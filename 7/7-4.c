#include <stdio.h>
#define MAX 100

int main(void) {
    char ch[MAX];
    int i, count;
    printf("Enter a string:\n");
    for (i = 0, count = 0; i < MAX; i++) {
        if (scanf("%c", &ch[i]) == 1 && ch[i] != '#') {
            if (ch[i] == '.') {
                printf("!");
            }
            else if (ch[i] == '!') {
                printf("!!");
            }
            else {
                printf("%c", ch[i]);
            }
            count++;
        }
        else {
            break;
        }
    }
    printf("\nYou've entered %d charactors.", count);
    return 0;
}
