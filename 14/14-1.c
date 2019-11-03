#include <stdio.h>

struct month {
    char name[10];
    char mon[4];
    int days;
    int m;
};

void print_mon(const struct month *M) {
    printf("Name\t%s\nShort\t%s\nDays\t%d\nNumber\t%d\n\n",
            M->name, M->mon, M->days, M->m);
}

int main(void) {
    int i;
    const struct month Months[12] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}
    };
    const struct month *M = Months;
    for (i = 0; i < 12; i++)
        print_mon(M + i);
    return 0;
}
