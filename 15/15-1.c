#include <stdio.h>
#include <string.h>

int strtodec(char *ch) {
    int count;
    int result = 0;
    int i;
    count = strlen(ch);
    printf("Binary string length = %d\n", count);
    for (i = 0; i < count; i++)
        if (*(ch + i) == '1')
            result += 1<<(count - 1 - i);
    return result;
}

int strcheck(char *ch) {
    while (*ch) {
        if (*ch != '0' && *ch != '1')
            return -1;
        ch++;
    }
    return 0;
}

int main(void) {
    char str[32];
    puts("Enter a binary string");
    gets(str);
    if (strlen(str) >= 32) {
        fprintf(stderr, "Invalid input. Must be less than 32bit\n");
        return -1;
    }
    else if (strcheck(str) == -1) {
        fprintf(stderr, "Invalid input. Must be 0 or 1 in the string\n");
        return -1;
    }
    else {
        printf("%d", strtodec(str));
        return 0;
    }
}
