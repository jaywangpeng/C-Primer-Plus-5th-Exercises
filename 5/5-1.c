#include <stdio.h>

int main(void) {
    const int cycle = 60;
    int min;
    printf("Enter the minutes to convert:\n");
    scanf("%d", &min);
    while (min > 0) {
        printf("%d minutes --> %d hours and %d minutes\n",
                min, min / cycle, min % cycle);
        printf("Enter the minutes to convert:\n");
        scanf("%d", &min);
    }
    return 0;
}
