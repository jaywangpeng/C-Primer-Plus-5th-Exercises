#include <stdio.h>

int main(void) {
    int n[100], i, j;
    int odd_count = 0, even_count = 0, odd_sum = 0, even_sum = 0;
    printf("Enter some integers. 0 to exit.\n");
    i = 0;
    while (scanf("%d", &n[i]) == 1) {
        if (n[i] == 0) break;
        i++;
    }
    for (j = 0; j < i; j++) {
        if (n[j] % 2 == 0) {
            even_count++;
            even_sum += n[j];
        }
        else {
            odd_count++;
            odd_sum += n[j];
        }
    }
    printf("Count of even number: %d\n", even_count);
    printf("Average of even number: %d\n", even_sum / even_count);
    printf("Count of odd number: %d\n", odd_count);
    printf("Average of odd number: %d\n", odd_sum / odd_count);
    return 0;
}
