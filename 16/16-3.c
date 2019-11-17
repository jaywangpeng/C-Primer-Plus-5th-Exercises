#include <stdio.h>
#include <math.h>

#define PI 3.141592654
#define CLRINPUT while(getchar() != '\n') continue

struct cartesian {
    double x;
    double y;
};

struct polar {
    double a;
    double r;
};

void convert(struct polar *P, struct cartesian *C) {
    double radian;
    radian = (P->a * PI) / 180.0;
    C->x = P->r * cos(radian);
    C->y = P->r * sin(radian);
}

int main(void) {
    struct polar p;
    struct cartesian c;
    puts("Enter Polar Coordinates: Angel");
    scanf("%lf", &p.a);
    CLRINPUT;
    puts("Enter Polar Coordinates: Diagonal");
    scanf("%lf", &p.r);
    CLRINPUT;
    convert(&p, &c);
    printf("Polar coordinates: Angel = %.2lf, Diagnoal = %.2lf\n", p.a, p.r);
    printf("Cartesian coordinates: X = %.2lf, Y = %.2lf\n", c.x, c.y);
}
