#include <stdio.h>
#include "hello.h"

void f1() {
    char *str = "This is f1";
    char *p = &str[0];
    while(*p != '\0') {
        printf("%-2c", *p);
        p++;
    }
    printf("\n%s\n", str);
}

void f2() {
    // 1 + 2 + ... + 10
    int i = 0;
    int s = 0;
    for (i = 1; i <= 10; ++i) {
        s += i;
    }
    printf("S = %d\n", s);
}

int main(int argc, char *argv[]) {
    int i = 2;
    int j = 4;
    int s = i + j;
    printf("s = %d\n", s);
    f1();
    f2();
    f3(2, 5);
    f4();

    return 0;
}


