#include <stdio.h>
#define TAXRATE1 0.15
#define TAXRATE2 0.28
#define TAXBASE1 17850.00
#define TAXBASE2 23900.00
#define TAXBASE3 29750.00
#define TAXBASE4 14875.00

int main(void) {
    int status;
    float tax, income;
    while (1) {
        printf("Choose your status:\n");
        printf("1. Single\n");
        printf("2. Owner\n");
        printf("3. Married and shared\n");
        printf("4. Married but divorced\n");
        if (scanf("%d", &status) != 1) {
            return 1;
        }
        if (status < 1 || status > 4) {
            return 1;
        }
        printf("Enter your yearly income:\n");
        scanf("%f", &income);
        if (income <= TAXBASE1) {
            status = 5;
        }
        switch (status) {
            case 1 :
                tax = TAXBASE1 * TAXRATE1 + (income - TAXBASE1) * TAXRATE2;
                break;
            case 2 :
                tax = TAXBASE2 * TAXRATE1 + (income - TAXBASE2) * TAXRATE2;
                break;
            case 3 :
                tax = TAXBASE3 * TAXRATE1 + (income - TAXBASE3) * TAXRATE2;
                break;
            case 4 :
                tax = TAXBASE4 * TAXRATE1 + (income - TAXBASE4) * TAXRATE2;
                break;
            case 5 :
                tax = income * TAXRATE1;
                break;
            default :
                tax = 0;
                printf("Wrong input.\n");
                break;
        }
        printf("Your yearly tax is %.2f\n", tax);
    }
    return 0;
}
