#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s base exponent\n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    printf("use the standard math library\n");
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);

    multitab(exponent);

    sqrt_pi();

    return 0;
}



