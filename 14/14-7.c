#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   10

struct book {
    int id;
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void add(struct book *B, int i) {
    (B + i)->id = i + 1;
    puts("Now enter the title.");
    gets((B + i)->title);
    puts("Now enter the author.");
    gets((B + i)->author);
    puts("Now enter the value.");
    scanf("%f", &(B + i)->value);
    while (getchar() != '\n')
        continue;
}

void modify(struct book *B, int i, struct book *temp) {
    strcpy((B + i)->author, temp->author);
    strcpy((B + i)->title, temp->title);
    (B + i)->value = temp->value;
}

void delete(struct book *B, int i) {
    (B + i)->id = 0;
    (B + i)->title[0] = '\0';
    (B + i)->author[0] = '\0';
    (B + i)->value = 0;
}

void show(struct book *B, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if ((B + i)->id == 0)
            continue;
        printf("%d. %s by %s: $%.2f\n",
            (B + i)->id, (B + i)->title, (B + i)->author, (B + i)->value);
    }
}

void init(struct book *B, int n) {
    int i;
    for (i = 0; i < n; i++) {
        (B + i)->id = 0;
        (B + i)->title[0] = '\0';
        (B + i)->author[0] = '\0';
        (B + i)->value = 0;
    }
}

int find_spot(struct book *B, int n) {
    int i;
    for (i = 0; i < n; i++)
        if ((B + i)->id == 0)
            break;
    if (i == n)
        return -1;
    else
        return i;
}

int main(void) {
    struct book library[MAXBKS];
    struct book temp;
    int spot, i, found, count = 0;
    FILE * pbooks;
    int size = sizeof(struct book);
    char ch;

    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    init(library, MAXBKS);
    show(library, MAXBKS);
    while (count < MAXBKS && fread(library + count, size, 1, pbooks) == 1)
        count++;
    puts("Current contents of book.dat:");
    show(library, count);
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Choose what to do:");
    puts("a to add, m to modify, d to delete, s to show, q to quit");
    while ((ch = getchar()) != 'q') {
        while (getchar() != '\n')
            continue;
        switch (ch) {
            case 'a':
                if (count >= MAXBKS
                        || (spot = find_spot(library, MAXBKS)) == -1) {
                    puts("No more space to add records.");
                    break;
                }
                add(library, spot);
                count++;
                break;
            case 'd':
                puts("Which index number to delete");
                scanf("%d", &spot);
                while (getchar() != '\n')
                    continue;
                if (spot > 0 && spot <= MAXBKS)
                    delete(library, spot - 1);
                else
                    printf("Invalid index %d\n", spot);
                break;
            case 'm':
                puts("Which index number to modify");
                scanf("%d", &spot);
                while (getchar() != '\n')
                    continue;
                for (i = 0, found = 0; i < MAXBKS; i++)
                    if (spot > 0 && spot <= MAXBKS && spot == library[i].id) {
                        found = 1;
                        break;
                    }
                if (found) {
                    puts("Enter the new title");
                    gets(temp.title);
                    puts("Enter the new author");
                    gets(temp.author);
                    puts("Enter the new value");
                    scanf("%f", &temp.value);
                    while (getchar() != '\n')
                        continue;
                    modify(library, spot - 1, &temp);
                }
                else
                    printf("Invalid index %d\n", spot);
                break;
            case 's':
                show(library, count);
                break;
            default:
                break;
        }
        puts("a to add, m to modify, d to delete, s to show, q to quit");
    }
    if (count > 0) {
        puts("Here is the list of your books:");
        show(library, count);
        rewind(pbooks);
        fwrite(library, size, count, pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}
