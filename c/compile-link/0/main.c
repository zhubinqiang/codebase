#include <stdio.h>
#include "stack.c"

int a;
int b = -1;

int main(int argc, char *argv[]) {
    push('a');
    push('b');
    push('c');

    while(! is_empty()) {
        putchar(pop());
    }
    putchar('\n');
    return 0;
}


