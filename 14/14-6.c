#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PLIM 19

struct player {
    int id;
    char fn[20];
    char ln[20];
    int played;
    int hits;
    int bases;
    int rbi;
    double hitrate;
};

void init(int n, struct player *P) {
    int i;
    for (i = 0; i < n; i++) {
        (P + i)->id = 0;
        (P + i)->fn[0] = '\0';
        (P + i)->ln[0] = '\0';
        (P + i)->played = 0;
        (P + i)->hits = 0;
        (P + i)->bases = 0;
        (P + i)->rbi = 0;
        (P + i)->hitrate = 0.0;
    }
}

void add_record(struct player *P, int i, struct player *temp) {
    (P + i)->id = i;
    strcpy((P + i)->fn, temp->fn);
    strcpy((P + i)->ln, temp->ln);
    (P + i)->played = temp->played;
    (P + i)->hits = temp->hits;
    (P + i)->bases = temp->bases;
    (P + i)->rbi = temp->rbi;
}

void update_record(struct player *P, int i, struct player *temp) {
    (P + i)->played += temp->played;
    (P + i)->hits += temp->hits;
    (P + i)->bases += temp->bases;
    (P + i)->rbi += temp->rbi;
}

void get_name(char *name, int length, FILE *fp) {
    int i;
    char ch;
    for (i = 0; (ch = getc(fp)) != ' '; i++)
        name[i] = ch;
    if (i + 1 < length)
        name[i + 1] = '\0';
}

void show_record(struct player *P, int n) {
    int i;
    puts("\nPlayer ID | Player Name | Played games | Hits | Bases | RBI | HitRate");
    for (i = 0; i < n; i++) {
        if ((P + i)->id == 0)
            continue;
        printf("%d | %s %s | %d | %d | %d | %d | %.1lf%%\n",
                (P + i)->id, (P + i)->fn, (P + i)->ln,
                (P + i)->played, (P + i)->hits, (P + i)->bases, (P + i)->rbi,
                (P + i)->hitrate * 100.0);
    }
    putchar('\n');
}

void calc_hitrate(struct player *P, int n) {
    int i;
    for (i = 0; i < n; i++)
        if ((P + i)->id != 0)
            (P + i)->hitrate = (double)(P + i)->hits / (double)(P + i)->played;
}

int main(void) {
    struct player p[PLIM];
    struct player temp;
    FILE *fp;
    char file[30];
    int i, j, found;

    init(PLIM, p);
    puts("Enter the file name to read");
    gets(file);
    if ((fp = fopen(file, "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", file);
        exit(EXIT_FAILURE);
    }
    for (i = 0; fscanf(fp, "%d", &temp.id) == 1; i++) {
        fscanf(fp, "%s %s", temp.fn, temp.ln);
        fscanf(fp, "%d %d %d %d",
                &temp.played, &temp.hits, &temp.bases, &temp.rbi);
        for (j = 0, found = 0; j < PLIM; j++)
            if (temp.id == p[j].id) {
                found = 1;
                break;
            }
        if (found)
            update_record(p, temp.id, &temp);
        else
            add_record(p, temp.id, &temp);
    }
    calc_hitrate(p, PLIM);
    show_record(p, PLIM);
    fclose(fp);
    return 0;
}
