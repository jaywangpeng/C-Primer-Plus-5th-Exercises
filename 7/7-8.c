#include <stdio.h>
#define BASEHOURS 40
#define HOURLYPAY1 8.75
#define HOURLYPAY2 9.33
#define HOURLYPAY3 10.00
#define HOURLYPAY4 11.20
#define TAXRATE1 0.15
#define TAXRATE2 0.20
#define TAXRATE3 0.25
#define TAXLEVEL1 300.00
#define TAXLEVEL2 450.00

void printstar(int max) {
    int i;
    if (max >= 0 && max < 100) {
        for (i = 0; i < max; i++)
            printf("*");
    }
    printf("\n");
}

int main(void) {
    float hourlypay, salary, tax;
    float gap1, gap2;
    int hours, menu;
    printstar(50);
    printf("Enter the number corresponding to ");
    printf("the desired pay rate or action:\n");
    printf("1) $%.2f/hr\n", HOURLYPAY1);
    printf("2) $%.2f/hr\n", HOURLYPAY2);
    printf("3) $%.2f/hr\n", HOURLYPAY3);
    printf("4) $%.2f/hr\n", HOURLYPAY4);
    printf("5) quit\n");
    printstar(50);
    if (scanf("%d", &menu) == 1) {
        switch (menu) {
            case 1: { hourlypay = HOURLYPAY1; break; }
            case 2: { hourlypay = HOURLYPAY2; break; }
            case 3: { hourlypay = HOURLYPAY3; break; }
            case 4: { hourlypay = HOURLYPAY4; break; }
            default : { return 0; }
        }
    }
    else {
        return 1;
    }
    printf("Enter total working hours per week:");
    if (scanf("%d", &hours) != 1) {
        return 1;
    }
    if (hours > BASEHOURS ) {
        salary = (BASEHOURS + (hours - BASEHOURS) * 1.5) * hourlypay;
    }
    else {
        salary = hours * hourlypay;
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
