#include <stdio.h>
#define HOURLYPAY 10.00
#define BASEHOURS 40
#define TAXRATE1 0.15
#define TAXRATE2 0.20
#define TAXRATE3 0.25
#define TAXLEVEL1 300.00
#define TAXLEVEL2 450.00

int main(void) {
    float salary, tax;
    float gap1, gap2;
    int hours;
    printf("Enter total working hours per week:\n");
    if (scanf("%d", &hours) != 1) {
        return 1;
    }
    if (hours > BASEHOURS ) {
        salary = (BASEHOURS + (hours - BASEHOURS) * 1.5) * HOURLYPAY;
    }
    else {
        salary = hours * HOURLYPAY;
    }
    gap1 = salary - TAXLEVEL1;
    gap2 = salary - TAXLEVEL2;
    if (gap1 <= 0) {
        tax = salary * TAXRATE1;
    }
    else if (gap1 > 0 && gap2 <= 0) {
        tax = TAXLEVEL1 * TAXRATE1 + gap1 * TAXRATE2;
    }
    else if (gap1 > 0 && gap2 > 0) {
        tax = TAXLEVEL1 * TAXRATE1 +
             (TAXLEVEL2 - TAXLEVEL1) * TAXRATE2 +
              gap2 * TAXRATE3;
    }
    else {
        tax = 0;
    }
    printf("Your weekly salary is %.2f\n", salary);
    printf("Your weekly tax is %.2f\n", tax);
    printf("Your weekly net salary is %.2f\n", salary - tax);
    return 0;
}
