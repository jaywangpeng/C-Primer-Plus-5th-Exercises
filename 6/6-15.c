#include <stdio.h>
#define RATEa 0.1
#define RATEb 0.05

int main(void) {
    float a = 100.0, r1 = 0, r2 = 0;
    int year = 1, i;
    printf("client a and b both have $100.\n");
    for (year = 1; r2 <= r1; year++) {
        r1 = a + a * RATEa * year;
        printf("r1 = %f\n", r1);
        for (i = 0, r2 = a; i < year; i++) {
            r2 = r2 + r2 * RATEb;
        }
        printf("r2 = %f\n", r2);
    }
    printf("After %d years:\n", year);
    printf("client a has %.2f with yearly rate %.2f\n", r1, RATEa);
    printf("client b has %.2f with yearly rate %.2f\n", r2, RATEb);
}
