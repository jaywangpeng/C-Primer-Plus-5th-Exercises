#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_title(const int count, struct book *B[]) {
    int i, j;
    struct book *temp;
    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
            if (strcmp(B[i]->title, B[j]->title) > 0) {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
}

void sort_value(const int count, struct book *B[]) {
    int i, j;
    struct book *temp;
    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
            if (B[i]->value > B[j]->value) {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
}

int main(void) {
    struct book library[MAXBKS];
    struct book *B[MAXBKS];
    int count = 0;
    int i;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS &&
            gets(library[count].title) != NULL &&
            library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        gets(library[count].author);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        B[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n",
                    library[i].title, library[i].author, library[i].value);
        printf("Sorted by title:\n");
        sort_title(count, B);
        for (i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n",
                    B[i]->title, B[i]->author, B[i]->value);
        printf("Sorted by value:\n");
        sort_value(count, B);
        for (i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n",
                    B[i]->title, B[i]->author, B[i]->value);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
}
