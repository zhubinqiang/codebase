#include <stdio.h>

void sum(int start, int end) {
    int s = 0;
    int i;
    for (i = start; i <= end; ++i) {
        s += i;
    }
    printf("S = %d + ... + %d = %d", start, end, s);
}

int main(int argc, char *argv[])
{
    sum(1, 100);
    return 0;
}
