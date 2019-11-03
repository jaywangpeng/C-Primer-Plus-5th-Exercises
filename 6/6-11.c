#include <stdio.h>

int main(void) {
    int i, count;
    double a, result1, result2;
    printf("Enter a count:");
    while (scanf("%d", &count) == 1) {
        for (i = 0, a = 1.0, result1 = 0; i < count; i++) {
            result1 += a / (a + i);
        }
        printf("Sum1 = %e\n", result1);
        for (i = 0, a = 1.0, result2 = 0; i < count; i++) {
            if (i % 2 == 1) {
                result2 -= a / (a + i);
            }
            else {
                result2 += a / (a + i);
            }
        }
        printf("Sum2 = %e\n", result2);
        printf("Enter a count:");
    }
}
