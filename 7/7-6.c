#include <stdio.h>
#define MAX 100

int main(void) {
    char ch[MAX], temp;
    int i, count = 0;
    printf("Enter a string:\n");
    for (i = 0; i < MAX; i++) {
        if (scanf("%c", &ch[i]) == 1 && ch[i] != '#') {
            if (i != 0 && ch[i - 1] == 'e' && ch[i] == 'i') {
                count++;
            }
        }
        else
            break;
    }
    printf("You've entered %d times of 'ei'", count);
}
