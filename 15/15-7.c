#include <stdio.h>

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define ALM_MASK 0x18000
#define BOLD_MASK 0x20000
#define ITALIC_MASK 0x40000
#define UNDERLINE_MASK 0x80000
#define CENTER 0x08000
#define RIGHT 0x10000
#define BOLD 0
#define ITALIC 1
#define UNDERLINE 2
#define FONT 0xA0A

char *alm[] = { "left", "center", "right" };
char *style[] = { "bold", "italic", "underline" };

void show_menu(void) {
    char *menu = "f) change font\n"
                 "s) change size\n"
                 "a) change alignment\n"
                 "b) toggle bold\n"
                 "i) toggle italic\n"
                 "u) toggle underline\n"
                 "q) quit";
    puts(menu);
}

void show_font(unsigned long ft) {
    puts("Font settings as below");
    puts("ID\tSIZE\tALIGNMENT\tB\tI\tU");
    printf("%lu\t%lu\t%s\t\t%s\t%s\t%s\n",
            ft & ID_MASK,
            (ft & SIZE_MASK) >> 8,
            alm[(ft & ALM_MASK) >> 15],
            (ft & BOLD_MASK) >> 17 ? "on" : "off",
            (ft & ITALIC_MASK) >> 18 ? "on" : "off",
            (ft & UNDERLINE_MASK) >> 19 ? "on" : "off");
}

int main(void) {
    unsigned long font = FONT;
    char ch;
    unsigned int n;
    show_font(font);
    show_menu();
    while ((ch = getchar()) != '\n') {
        while (getchar() != '\n')
            continue;
        switch (ch) {
            case 'f' : 
                while (1) {
                    puts("Enter font number");
                    scanf("%d", &n);
                    while (getchar() != '\n')
                        continue;
                    if (n > 0 && n < 255)
                        break;
                    else
                        puts("Must between 0 and 255");
                }
                font &= ~ID_MASK;
                font |= n & ID_MASK;
                break;
            case 's' :
                while (1) {
                    puts("Enter size number");
                    scanf("%d", &n);
                    while (getchar() != '\n')
                        continue;
                    if (n > 0 && n < 127)
                        break;
                    else
                        puts("Must between 0 and 127");
                }
                font &= ~SIZE_MASK;
                font |= (n << 8) & SIZE_MASK;
                break;
            case 'a' :
                while (1) {
                    puts("Choose alignment:");
                    printf("0) %s; 1) %s; 2) %s\n",
                            alm[0], alm[1], alm[2]);
                    scanf("%d", &n);
                    while (getchar() != '\n')
                        continue;
                    if (n >= 0 && n <=2) {
                        font &= ~ALM_MASK;
                        switch (n) {
                            case 1:
                                font |= CENTER & ALM_MASK; break;
                            case 2:
                                font |= RIGHT & ALM_MASK; break;
                        }
                        break;
                    }
                    else puts("Invalid input"); 
                }
                break;
            case 'b' : font ^= BOLD_MASK; break;
            case 'i' : font ^= ITALIC_MASK; break;
            case 'u' : font ^= UNDERLINE_MASK; break;
            case 'q' : puts("Bye"); break;
            default : break;
        }
        if (ch == 'q')
            break;
        show_font(font);
        show_menu();
    }
    return 0;
}
