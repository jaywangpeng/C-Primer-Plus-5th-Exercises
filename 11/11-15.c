#include <stdio.h>
#include <ctype.h>

#define MAX 1000

void lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void upper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main(int argc, char *argv[]) {
    int i = 0;
    char content[MAX];
    char *p;
    if (!argv[1]) {
        puts("Usage: 11-15.exe <-p/-u/-l>; (max characters = 1000)\n"
             "  -p print the contents\n"
             "  -u change contents to upper case\n"
             "  -l change contents to lower case");
        return -1;
    }
    else
        p = content;
    puts("Enter contents");
    while ((content[i] = getchar()) != EOF)
        i++;
    for (i = 1; i < argc; i++) {
        puts(argv[i]);
        if (!strcmp(argv[i], "-p")) {
            puts("Original input");
            puts(content);
        }
        else if (!strcmp(argv[i], "-u")) {
            upper(content);
            puts("Upper case");
            puts(content);
        }
        else if (!strcmp(argv[i], "-l")) {
            lower(content);
            puts("Lower case");
            puts(content);
        }
    }
    return 0;
}
