#include <stdio.h>

void f3(int low, int hight) {
    int i = 0;
    int s = 0;
    for (i = low; i < hight; ++i) {
        s += i;
    }
    printf("f3: S = %d\n", s);
}

