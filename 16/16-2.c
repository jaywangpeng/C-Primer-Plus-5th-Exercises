#include <stdio.h>

#define AVG(X, Y) 1.0/((1.0/(X)+1.0/(Y))/2.0)

int main(void) {
    float x = 2.0, y = 4.0;
    printf("X = %f, Y = %f, AVG = %f\n", x, y, AVG(x, y));
    return 0;
}
