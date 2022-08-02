#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    push('a');
    push('b');
    push('c');

    putchar(pop());
    // while(! is_empty()) {
    //     putchar(pop());
    // }
    // putchar('\n');
    return 0;
}


