#include <stdio.h>
#include "mymath.h"

void multitab(int n) {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) {
            printf("%dx%d=%-2d  ", j, i, i*j);
        }
        printf("\n");
    }
}


