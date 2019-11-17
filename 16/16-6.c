#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 5

struct names {
    char first[40];
    char last[40];
};

void showarray(struct names N[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%s %s\n", N[i].first, N[i].last);
}

int comp(const void *p1, const void *p2) {
    const struct names *pn1 = (const struct names *)p1;
    const struct names *pn2 = (const struct names *)p2;
    int result;
    result = strcmp(pn1->first, pn2->first);
    if (result != 0)
        return result;
    else
        return strcmp(pn1->last, pn2->last);
}

int main(void) {
    struct names staff[NUM] = {
        { "Peter", "Jackson" },
        { "Nicole", "Lee" },
        { "Alex", "Chen" },
        { "George", "Lucas" },
        { "Chris", "Paul" }
    };
    puts("Random list:");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(struct names), comp);
    puts("\nSorted list:");
    showarray(staff, NUM);
    return 0;
}
