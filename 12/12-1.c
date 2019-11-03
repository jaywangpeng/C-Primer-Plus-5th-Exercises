#include <stdio.h>

void critic(int *p) {
    puts("No luck, chummy. Try again.");
    scanf("%d", p);
}

int main(void) {
    int units = 0;
    int *p = &units;
    puts("How many pounds to a firkin of butter?");
    scanf("%d", p);
    while (*p != 56) {
        critic(p);
    }
    puts("You must have looked it up!");
    return 0;
}
