#include <stdio.h>
#include "mymath.h"
#include <math.h>

void multitab(int n) {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) {
            printf("%dx%d=%-2d  ", j, i, i*j);
        }
        printf("\n");
    }
}

void sqrt_pi() {
    printf("sqrt of pi = %f\n", sqrt(M_PI));
}


