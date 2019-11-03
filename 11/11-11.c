#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int word_c, upper_c, lower_c, punc_c, num_c, previous;
    word_c = upper_c = lower_c = punc_c = num_c = previous = 0;
    puts("Enter a string with any characters. Ctrl+Z, enter to exit");
    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            upper_c++;
            previous = 1;
        }
        else if (islower(ch)) {
            lower_c++;
            previous = 1;
        }
        else if (ispunct(ch)) {
            punc_c++;
            previous = 1;
        }
        else if (isdigit(ch)) {
            num_c++;
            previous = 1;
        }
        else if (isspace(ch) && previous == 1) {
            previous = 0;
            word_c++;
        }
    }
    printf("Word count:\t%d\n", word_c);
    printf("Uppercase count:\t%d\n", upper_c);
    printf("Lowercase count:\t%d\n", lower_c);
    printf("Puncuation count:\t%d\n", punc_c);
    printf("Number count:\t%d\n", num_c);
}
