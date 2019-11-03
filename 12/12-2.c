#include <stdio.h>
#include "12-2.h"

int mode;
float distance = 0;
float fuel = 0;

int main(void) {
    puts("Enter 0 for metric mdoe, 1 for US mode:");
    if (scanf("%d", &mode) != 1) {
        puts("Must be a number.");
        return -1;
    }
    while (mode >= 0) {
        set_mode(mode);
        get_info();
        if (distance > 0 && fuel > 0)
            show_info();
        else {
            puts("Invalid distance or fuel");
            return -1;
        }
        puts("Enter 0 for metric mdoe, 1 for US mode. (-1 to quit)");
        scanf("%d", &mode);
    }
    return 0;
}
