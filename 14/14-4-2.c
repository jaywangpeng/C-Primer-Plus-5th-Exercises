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

void display(struct person p) {
    char ch;
    printf("%s, %s", p.fullname.ln, p.fullname.fn);
    if ((ch = p.fullname.mn[0]) != '\0')
        printf(" %c.", toupper(ch));
    printf(" - %d\n", p.id);
}

int main(void) {
    struct person people[5] = {
        {10000, {"Peter", "ab", "Li"}},
        {10001, {"Alex", "cd", "Sun"}},
        {10002, {"Lisa", "", "Zhao"}},
        {10003, {"Vincent", "gh", "Wang"}},
        {10004, {"Laura", "ij", "Zhang"}}
    };
    int i;
    for (i = 0; i < 5; i++)
        display(people[i]);
}
