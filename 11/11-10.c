#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 10
#define MAXLEN 100

void sort_pstr(char *str[], int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void sort_pair_len(char *str[], int len[], int n) {
    int i, j;
    int itemp;
    char *ctemp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (len[i] > len[j]) {
                itemp = len[i];
                len[i] = len[j];
                len[j] = itemp;
                ctemp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = ctemp;
            }
        }
    }
}

void func1(char *str[], int n) {
    int i;
    for (i = 0; i < n; i++)
        puts(str[i]);
}

void func2(char *str[], int n) {
    int i, j;
    sort_pstr(str, n);
    func1(str, n);
}

void func3(char *str[], int n) {
    int i, j, itemp;
    int len[MAXSTR];
    char *ctemp;
    for (i = 0; i < n; i++)
        len[i] = strlen(str[i]);
    sort_pair_len(str, len, n);
    func1(str, n);
}

void func4(char *str[], int n) {
    int i, j, itemp;
    int len[MAXSTR];
    char *ch, *ctemp;
    for (i = 0; i < n; i++) {
        len[i] = 0;
        for (ch = str[i]; isalpha(*ch); ch++)
            len[i]++;
    }
    sort_pair_len(str, len, n);
    func1(str, n);
}

int main(void) {
    int i = 0;
    int ch, m;
    char strings[MAXSTR][MAXLEN];
    char *pstr[MAXSTR];
    char menu[] =
        "Menu:\n"
        "1. Display all original strings\n"
        "2. Display all strings in ASCII order of first character\n"
        "3. Display all strings ordered by string length\n"
        "4. Display all strings ordered by first word length in the string\n"
        "5. Quit\n";
    puts("Enter some strings in each line: (Max 10 lines)");
    while ((ch = getchar()) != EOF && ch != '\n' && i < 10) {
        strings[i][0] = ch;
        gets(strings[i] + 1);
        pstr[i] = strings[i];
        i++;
    }
    puts(menu);
    puts("Enter the menu number:");
    while (scanf("%d", &m) == 1) {
        switch (m) {
            case 1:
                func1(pstr, i);
                break;
            case 2:
                func2(pstr, i);
                break;
            case 3:
                func3(pstr, i);
                break;
            case 4:
                func4(pstr, i);
                break;
        }
        if (m == 5)
            break;
        else
            puts("Enter the menu number:");
    }
    return 0;
}
