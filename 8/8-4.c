#include <stdio.h>

int main(void) {
    int wc = 0, totalch = 0, prespace = 0, ch;

    printf("Enter some words, I will calculate average length of them:\n");
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            prespace = 1;
        }
        else if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123)) {
            totalch++;
            if (prespace) {
                prespace = 0;
                wc++;
            }
        }
        else if (ch == '\n' && prespace == 1)
            prespace = 0;
        else if (ch == '\n' && prespace == 0)
            wc++;
    }
    printf("Total characters: %d\n", totalch);
    printf("Word count: %d\n", totalch > 0 ? wc : 0);
    printf("Average word length: %d\n", wc > 0 ? totalch/wc : 0);
    return 0;
}
