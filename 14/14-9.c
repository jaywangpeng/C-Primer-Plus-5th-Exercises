#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSEATS 12
#define MAXFLT 4

struct seat {
    int id;
    int alloc;
    char fn[20];
    char ln[20];
};

struct flight {
    char id[10];
    struct seat seats[MAXSEATS];
};

void init_seat(struct seat *S, int n) {
    int i;
    for (i = 0; i < n; i++) {
        (S + i)->alloc = 0;
        (S + i)->id = i;
        (S + i)->fn[0] = '\0';
        (S + i)->ln[0] = '\0';
    }
}

void init_flight(struct flight *F, int n, int m, const char *flightID[MAXFLT]) {
    int i;
    for (i = 0; i < n; i++) {
        strcpy((F + i)->id, *(flightID + i));
        init_seat((F + i)->seats, m);
    }
}

void sh_empty_num(struct seat *S, int n) {
    int i, count;
    puts("Number of empty seats: ");
    for (i = 0, count = 0; i < n; i++)
        if ((S + i)->alloc == 0)
            count++;
    printf("%d\n", count);
}

void sh_list(struct seat *S, int n, int empty) {
    int i;
    if (empty) {
        for (i = 0; i < n; i++) {
            if (i == 0)
                puts("Empty seat IDs:");
            if ((S + i)->alloc == 0)
                printf("%d\n", (S + i)->id);
        }
    }
    else {
        for (i = 0; i < n; i++) {
            if (i == 0)
                puts("Allocated seat IDs:");
            if ((S + i)->alloc == 1)
                printf("%d: %s %s\n", (S + i)->id, (S + i)->fn, (S + i)->ln);
        }
    }
}

void swap(struct seat *A, struct seat *B) {
    struct seat temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void sort_list(struct seat *S, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp((S + i)->fn, (S + j)->fn) > 0)
                swap(S + i, S + j);
}

void assign_seat(struct seat *S, int n, char *fn, char *ln) {
    int i;
    for (i = 0; i < n; i++)
        if ((S + i)->alloc == 0)
            break;
    if (i != n) {
        (S + i)->id = i;
        (S + i)->alloc = 1;
        strcpy((S + i)->fn, fn);
        strcpy((S + i)->ln, ln);
        printf("Seat ID %d has been assigned to %s %s",
                (S + i)->id, (S + i)->fn, (S + i)->ln);
    }
    else
        puts("Sorry. No empty seat available.");
}

void del_seat(struct seat *S, int id) {
    int i;
    if (id >= 0 && id < MAXSEATS) {
        for (i = 0; i < MAXSEATS; i++) {
            if ((S + i)->id == id && (S + i)->alloc == 1) {
                (S + i)->alloc = 0;
                (S + i)->fn[0] = '\0';
                (S + i)->ln[0] = '\0';
                printf("Seat ID %d has been unassigned.\n", (S + i)->id);
                break;
            }
        }
    }
    else
        printf("Unable to find seat ID %d.\n", id);
}

void sh_menu() {
    char *menu = "\nTo choose a function, enter its letter label:\n"
        "a) Show number of empty seats\n"
        "b) Show list of empty seats\n"
        "c) Show alphabetical list of seats\n"
        "d) Assign a customer to a seat assignment\n"
        "e) Delete a seat assignment\n"
        "f) Back to previous menu\n";
    puts(menu);
}

void sh_flightid(const char *flightID[MAXFLT], int n) {
    int i;
    puts("\nChoose flight ID: (Enter q to exit)");
    for (i = 0; i < n; i++)
        printf("%d: Flight %s\n", i, *(flightID + i));
}

int main(void) {
    struct flight flights[MAXFLT];
    const char *flightID[MAXFLT] = {"102", "311", "444", "519"};
    FILE *fp;
    char ch, filename[50] = "flights.dat";
    int i;
    char fn[20], ln[20];

    if ((fp = fopen(filename, "r")) == NULL) {
        if ((fp = fopen(filename, "w+b")) == NULL) {
            fprintf(stderr, "Cannot create file %s\n", filename);
            exit(EXIT_FAILURE);
        }
    }
    else {
        if ((fp = fopen(filename, "r+b")) == NULL) {
            fprintf(stderr, "Cannot open file %s\n", filename);
            exit(EXIT_FAILURE);
        }
    }
    init_flight(flights, MAXFLT, MAXSEATS, flightID);
    for (i = 0; i < MAXFLT
        && fread(flights + i, sizeof(struct flight), 1, fp) == 1; i++) {
        if (i == 0)
            puts("Current contents of flights.dat");
        printf("\nFlight ID: %s\n", (flights + i)->id);
        sh_list((flights + i)->seats, MAXSEATS, 0);
    }
    sh_flightid(flightID, MAXFLT);
    while (scanf("%d", &i) == 1) {
        while (getchar() != '\n')
            continue;
        if (i < 0 || i > 3) {
            puts("Invalid input. Must be from 0 to 3");
            sh_flightid(flightID, MAXFLT);
            continue;
        }
        else
            sh_menu();
        while ((ch = getchar()) != 'f') {
            while (getchar() != '\n')
                continue;
            switch (ch) {
                case 'a':
                    sh_empty_num((flights + i)->seats, MAXSEATS);
                    break;
                case 'b':
                    sh_list((flights + i)->seats, MAXSEATS, 1);
                    break;
                case 'c':
                    sort_list((flights + i)->seats, MAXSEATS);
                    sh_list((flights + i)->seats, MAXSEATS, 0);
                    break;
                case 'd':
                    puts("Enter first name");
                    gets(fn);
                    puts("Enter last name");
                    gets(ln);
                    assign_seat((flights + i)->seats, MAXSEATS, fn, ln);
                    break;
                case 'e':
                    puts("Enter seat number");
                    if (scanf("%d", &i) == 1) {
                        while (getchar() != '\n')
                            continue;
                        del_seat((flights + i)->seats, i);
                    }
                    break;
                default:
                    break;
            }
            sh_menu();
        }
        sh_flightid(flightID, MAXFLT);
    }
    rewind(fp);
    fwrite(flights, sizeof(struct flight), MAXFLT, fp);
    fclose(fp);
    return 0;
}
