#include <stdio.h>

void fellow (void) {
    printf("For he's a jolly good fellow!\n");
}

void nobody (void) {
    printf("Which nobody can deny!");
}

int main (void) {
    int i = 1;
    while (i <= 3) {
        fellow();
        i++;
    }
    nobody();
    return 0;
}
