#include <stdio.h>

int power(int q, int p) {
    int i, result = 1;
    if (q < 0 && p < 0) {
        return 1;
    }
    if (p == 0) {
        result = 1;
    }
    else {
        for (i = 0; i < p; i++) {
            result = result * q;
        }
    }
    return result;
}

int main(void) {
    int i, n[8];
    for (i = 0; i < 8; i++) {
        n[i] = power(2, i);
        printf("Power %d of 2: %d\n", i, n[i]);
    }
}
