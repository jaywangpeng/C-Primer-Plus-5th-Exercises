#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay(int i) {
    clock_t a, b;
    a = clock();
    printf("a = %lf, after devide = %lf seconds\n",
            (double)a, (double)a / CLOCKS_PER_SEC);
#ifdef _WIN32
    Sleep(i);
#else
    sleep(i);
#endif
    b = clock();
    printf("b = %lf, after devide = %lf seconds\n",
            (double)b, (double)b / CLOCKS_PER_SEC);
    printf("The time between two invocations of clock() is %lf seconds\n",
            (double)(b - a) / CLOCKS_PER_SEC);
}

int main(void) {
    int i;
    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
    puts("Enter how many seconds to sleep");
    scanf("%d", &i);
    delay(i * 1000);
    return 0;
}
