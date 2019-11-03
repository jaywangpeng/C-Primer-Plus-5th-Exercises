#include <stdio.h>

void menu1(void) {
    char menu[] = "This is menu1";
    puts(menu);
}

void menu2(void) {
    char menu[] = "This is menu2";
    puts(menu);
}

int main(void) {
    void (*p[2])(void) = {menu1, menu2};
    char ch;
    puts("Choose a or b: (q to exit)");
    while ((ch = getchar()) != '\n') {
        while (getchar() != '\n')
            continue;
        switch (ch) {
            case 'a':
                (*p)();
                break;
            case 'b':
                (*(p + 1))();
                break;
            default:
                break;
        }
        if (ch == 'q')
            break;
        puts("Choose a or b: q to exit");
    }
}
