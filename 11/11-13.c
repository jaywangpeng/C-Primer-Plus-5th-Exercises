#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double base, result;
    int pow, temp;
    if (argc == 3) {
        result = base = atof(argv[1]);
        pow = temp = atoi(argv[2]);
        while (temp > 1) {
            result *= base;
            temp--;
        }
        printf("The power %d of %lf is: %lf\n", pow, base, result);
        return 0;
    }
    else {
        puts("First argument is a double and second argument is an integer.");
        return 1;
    }
}
