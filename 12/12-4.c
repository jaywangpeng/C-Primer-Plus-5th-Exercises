#include <stdio.h>

int count = 0;

int func(void) {
    printf("executing func() %d\n", count);
    return ++count;
}

int main(void) {
    char ch;
    int n = 0;
    puts("Enter how many times to call func. I will count it.");
    scanf("%d", &n);
    while (n--)
        func();
    printf("Count of func call is %d\n", count);
}
