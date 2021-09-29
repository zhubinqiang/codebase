#include <stdio.h>
#include <demo.h>

int main(int argc, char *argv[]) {
    int x = 2;
    int y = 3;
    int z = add(x, y);
    printf("%d + %d = %d\n", x, y, z);
    printf("power(%d, %d) = %f\n", x, y, power(x, y));
    print_pi();
    multitab(9);
    return 0;
}


