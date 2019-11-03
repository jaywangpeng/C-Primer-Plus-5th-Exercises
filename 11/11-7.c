#include <stdio.h>

char *string_in(char *s1, char *s2) {
    int i, j, k;
    char *target = NULL;
    for (i = 0, k = 0; i < strlen(s1); i++, k = 0) {
        printf("i = %d\n", i);
        for (j = 0; j < strlen(s2); j++) {
            printf("\tj = %d\n", j);
            if (*(s1 + i + j) != *(s2 + j)) {
                printf("\t\ts1: %c; s2 %c\n", *(s1 + i + j), *(s2 + j));
                break;
            }
            else {
                k++;
                printf("\t\ts1: %c; s2 %c\n", *(s1 + i + j), *(s2 + j));
            }
        }
        if (k == strlen(s2)) {
            target = s1 + i;
            break;
        }
    }
    return target;
}

int main(void) {
    char s1[100];
    char s2[100];
    char *target;
    puts("Find string2 in string1. y to continue. q to exit.");
    while (getchar() != 'q') {
        while (getchar() != '\n')
            continue;
        puts("Enter string1:");
        gets(s1);
        puts("Enter string2:");
        gets(s2);
        target = string_in(s1, s2);
        if (target) {
            printf("Found string s2 in s1. Starts at '%c%c%c' in s1\n",
                    *target, *(target + 1), *(target + 2));
        }
        else
            puts("Not found");
        puts("Find string2 in string1. y to continue. q to exit.");
    }
}
