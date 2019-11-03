#include <stdio.h>
#define MONTHS 12
#define YEARS   5

int main(void) {
    const float rain[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    const float (*pyear)[MONTHS] = rain;
    const float *pmonth = *pyear;
    float subtotal, total;
    int year, month;

    printf("YEAR\tRAINFALL(inches)\n");
    for (total = 0; pyear < rain + YEARS; pyear++) {
        for (subtotal = 0; pmonth < *pyear + MONTHS; pmonth++)
            subtotal += *pmonth;
        printf("%d\t%.1f\n", pyear - rain + 2000, subtotal);
        total += subtotal;
    }
    printf("\nThe yearly average is %.1f inches.\n", total/YEARS);

    printf("MONTHLY AVERAGES:\n");
    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    for (month = 0, pyear = rain; month < MONTHS; month++) {
        for (year = 0, total = 0; year < YEARS; year++)
            total += *(*(pyear + year) + month);
            printf("%.1f\t", total/YEARS);
    }
    printf("\n");

    return 0;
}
