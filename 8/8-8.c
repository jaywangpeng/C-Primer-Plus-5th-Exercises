#include <stdio.h>

double getNumber(void) {
    double n;
    while (scanf("%lf", &n) != 1) {
        while (getchar() != '\n')
            continue;
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 11: ");
    }
    return n;
}

void calculator (char op, double a, double b) {
    switch (op) {
        case 'a': //addition
            printf("%f + %f = %f\n", a, b, a + b);
            break;
        case 's': //subtraction
            printf("%f - %f = %f\n", a, b, a - b);
            break;
        case 'm': //multiplication
            printf("%f * %f = %f\n", a, b, a * b);
            break;
        case 'd': //division
            if (b != 0) {
                printf("%f / %f = %f\n", a, b, a / b);
            }
            else {
                printf("division by 0 is not allowed.\n");
            }
            break;
    }
}

int main (void) {
    char op;
    double a, b;
    while (1) {
        printf("Enter the operation of your choice:\n");
        printf("a. add\ns. subtract\nm. multiply\nd. divide\nq. quit\n");
        if ((op = getchar()) == 'q') {
            printf("Bye.\n");
            break;
        }
        else if (op == 'a' || op == 's' || op == 'm' || op == 'd') {
            printf("Enter first number:");
            a = getNumber();
            printf("Enter second number:");
            b = getNumber();
            calculator(op, a, b);
        }
        else {
            printf("Invalid input.\n");
        }
        while (getchar() != '\n')
            continue;
        printf("Let's do this again.\n");
    }
    return 0;
}
