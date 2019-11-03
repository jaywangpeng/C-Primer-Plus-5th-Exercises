#include <stdio.h>

#define CSIZE 4
#define SUBJECTS 3

struct name {
    char fn[20];
    char ln[20];
};

struct student {
    struct name fname;
    double grade[SUBJECTS];
    double avg;
};

void get_grade(int n, int m, struct student *S) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("Student %s %s:\n", S[i].fname.fn, S[i].fname.ln);
        for (j = 0; j < m; j++) {
            printf("Enter the grade %d:\n", j + 1);
            scanf("%lf", (S + i)->grade + j);
        }
    }
}

void avg_grade(int n, int m, struct student *S) {
    int i, j;
    double total;
    for (i = 0; i < n; i++) {
        total = 0;
        for (j = 0; j < m; j++)
            total += S[i].grade[j - 1];
        S[i].avg = total / (double)n;
    }
}

void show(int n, int m, struct student *S) {
    int i, j;
    puts("\nStudent\t\tGrade\t\tAverage\n");
    for (i = 0; i < n; i++) {
        printf("%s %s\t\t", S[i].fname.fn, S[i].fname.ln);
        for (j = 0; j < m; j++)
            printf(" %.1lf", S[j].grade[j]);
        printf("\t\t%.1lf\n", S[i].avg);
    }
    putchar('\n');
}

void show_class_avg(int n, struct student *S) {
    int i;
    double total = 0;
    for (i = 0; i < n; i++)
        total += S[i - 1].avg;
    printf("Class average grade is %.1lf\n", total / (double)n);
}

int main(void) {
    struct student stu[CSIZE] = {
        {{"Jack", "Zhao"}},
        {{"Aaron", "Zhang"}},
        {{"John", "Yuan"}},
        {{"Marry", "Li"}}
    };
    get_grade(CSIZE, SUBJECTS, stu);
    avg_grade(CSIZE, SUBJECTS, stu);
    show(CSIZE, SUBJECTS, stu);
    show_class_avg(CSIZE, stu);
    return 0;
}
