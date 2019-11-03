#include <stdio.h>
#include <ctype.h>

struct name {
    char fn[20];
    char mn[20];
    char ln[20];
};

struct person {
    int id;
    struct name fullname;
};

void display(struct person P[], int n) {
    int i;
    char ch;
    for (i = 0; i < 5; i++) {
        printf("%s, %s", P[i].fullname.ln, P[i].fullname.fn);
        if ((ch = P[i].fullname.mn[0]) != '\0')
            printf(" %c.", toupper(ch));
        printf(" - %d\n", P[i].id);
    }
}

int main(void) {
    struct person people[5] = {
        {10000, {"Peter", "ab", "Li"}},
        {10001, {"Alex", "cd", "Sun"}},
        {10002, {"Lisa", "", "Zhao"}},
        {10003, {"Vincent", "gh", "Wang"}},
        {10004, {"Laura", "ij", "Zhang"}}
    };
    display(people, 5);
}
