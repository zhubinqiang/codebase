#include <stdio.h>
#include <demo.h>

int x = 2;
int A;

int main(int argc, char *argv[]) {
    int y = 3;
    int z = add(x, y);
    printf("%d + %d = %d\n", x, y, z);
    printf("power(%d, %d) = %f\n", x, y, power(x, y));
    print_pi();

    A = 9;
    multitab(A);
    return 0;
}


