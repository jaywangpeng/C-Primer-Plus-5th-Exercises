#include <stdio.h>
#define RATE 0.08
#define BAL 1000000
#define WDRAW 100000

int main(void) {
    float balance = BAL;
    int year;
    printf("Chuckie has $1,000,000 dollors ");
    printf("and will withdraw $100,000 each year.\n");
    printf("Interest rate yearly is %.2f%%\n", RATE);
    for (year = 1; balance > 0; year++) {
        balance = balance + balance * RATE - WDRAW;
        printf("End of year %d balance: %.2f\n", year, balance);
    }
}
