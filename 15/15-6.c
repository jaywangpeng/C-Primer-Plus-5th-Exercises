#include <stdio.h>

#define FONT { 10, 20, 0, 1, 0, 0 }

struct font {
    unsigned int FontId    : 8;
    unsigned int FontSize  : 7;
    unsigned int Alignment : 2;
    unsigned int Bold      : 1;
    unsigned int Italic    : 1;
    unsigned int Underline : 1;
};

char *alm[] = { "left", "center", "right" };

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

void show_font(struct font *ft) {
    puts("Font settings as below");
    puts("ID\tSIZE\tALIGNMENT\tB\tI\tU");
    printf("%d\t%d\t%s\t\t%s\t%s\t%s\n",
            ft->FontId,
            ft->FontSize,
            alm[ft->Alignment],
            ft->Bold ? "on" : "off",
            ft->Italic ? "on" : "off",
            ft->Underline ? "on" : "off");
}

int main(void) {
    struct font ft = FONT;
    char ch;
    unsigned int n;
    show_font(&ft);
    show_menu();
    while ((ch = getchar()) != '\n') {
        while (getchar() != '\n')
            continue;
        switch (ch) {
            case 'f' : while (1) {
                               puts("Enter font number");
                               scanf("%u", &n);
                               while (getchar() != '\n')
                                   continue;
                               if (n > 0 && n < 255)
                                   break;
                               else
                                   puts("Must between 0 and 255");
                           }
                           ft.FontId = n;
                           break;
            case 's' : while (1) {
                               puts("Enter size number");
                               scanf("%u", &n);
                               while (getchar() != '\n')
                                   continue;
                               if (n > 0 && n < 127)
                                   break;
                               else
                                   puts("Must between 0 and 127");
                           }
                           ft.FontSize = n;
                           break;
            case 'a' : while (1) {
                               puts("Choose alignment:");
                               printf("0) %s; 1) %s; 2) %s\n",
                                       alm[0], alm[1], alm[2]);
                               scanf("%u", &n);
                               while (getchar() != '\n')
                                   continue;
                               if (n >= 0 && n <= 2)
                                   break;
                               else
                                   puts("Invalid input");
                           }
                           ft.Alignment = n;
                           break;
            case 'b' : ft.Bold ^= 1; break;
            case 'i' : ft.Italic ^= 1; break;
            case 'u' : ft.Underline ^= 1; break;
            case 'q' : puts("Bye"); break;
            default :
                break;
        }
        if (ch == 'q')
            break;
        show_font(&ft);
        show_menu();
    }
    return 0;
}
