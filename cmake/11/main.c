#include <stdio.h>
#include <stdlib.h>
#include <config.h>

#ifdef HAVE_POW
    #include <math.h>
#else
    #include "math/mathFunction.h"
#endif

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("%s Version %d.%d\n",
                argv[0],
                Demo_VERSION_MAJOR,
                Demo_VERSION_MINOR);
        printf("Usage: %s base exponent\n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef HAVE_POW
    printf("use the standard math library\n");
    double result = pow(base, exponent);
#else
    printf("use my own math library\n");
    double result = power(base, exponent);
#endif

    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}

