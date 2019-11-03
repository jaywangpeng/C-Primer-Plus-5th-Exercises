#include <stdio.h>
#include "12-3.h"

int main(void) {
    int mode = 0;
    float distance = 0;
    float fuel = 0;

    puts("Enter 0 for metric mdoe, 1 for US mode:");
    if (scanf("%d", &mode) != 1) {
        puts("Must be a number.");
        return -1;
    }
    while (mode >= 0) {
        set_mode(mode, &mode);
        get_info(mode, &distance, &fuel);
        if (distance > 0 && fuel > 0)
            show_info(mode, &distance, &fuel);
        else {
            puts("Invalid distance or fuel");
            return -1;
        }
        puts("Enter 0 for metric mdoe, 1 for US mode. (-1 to quit)");
        scanf("%d", &mode);
    }
    return 0;
}
