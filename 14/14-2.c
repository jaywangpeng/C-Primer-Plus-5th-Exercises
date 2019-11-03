#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[10];
    char mon[4];
    int days;
    char m[3];
};

const struct month Months[12] = {
    {"January", "Jan", 31, "1"},
    {"February", "Feb", 28, "2"},
    {"March", "Mar", 31, "3"},
    {"April", "Apr", 30, "4"},
    {"May", "May", 31, "5"},
    {"June", "Jun", 30, "6"},
    {"July", "Jul", 31, "7"},
    {"August", "Aug", 31, "8"},
    {"September", "Sep", 30, "9"},
    {"October", "Oct", 31, "10"},
    {"November", "Nov", 30, "11"},
    {"December", "Dec", 31, "12"}
};

int count_days(int d, char m[10], const struct month *M) {
    int i;
    m[0] = toupper(m[0]);
    for (i = 1; m[i] != '\0'; i++)
            m[i] = tolower(m[i]);
    if (d > 0 && d < 32) {
        for (i = 0; i < 12; i++)
            if (!strcmp(m, (M + i)->name)
                || !strcmp(m, (M + i)->mon)
                || !strcmp(m, (M + i)->m))
                break;
        while (i > 0) {
            d += (M + i - 1)->days;
            i--;
        }
        return d;
    }
    else {
        fprintf(stderr, "Invalid day input %d\n", d);
        return -1;
    }
}

int main(void) {
    int d, y;
    char m[10];
    const struct month *M = &Months[0];
    puts("Enter the year:");
    while (scanf("%d", &y) != 1)
        puts("Enter the year:");
    puts("Enter the month:");
    while (scanf("%s", m) != 1)
        puts("Enter the month:");
    puts("Enter the day:");
    while (scanf("%d", &d) != 1)
        puts("Enter the day:");
    printf("Days till this day in the year %d is %d", y, count_days(d, m, M));
    return 0;
}
