#include <stdio.h>

void smile ( void ) {
    printf("Smile!");
}

int main(void) {
    int i, j;
    for (i=0; i<3; i++) {
        for (j=3; j-i>0; j--) {
            smile();
        }
        printf("\n");
    }
    return 0;
}
