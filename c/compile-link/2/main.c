#include <stdio.h>

int a;
int b = -1;

/**
 * warning: implicit declaration of function ‘push’ [-Wimplicit-function-declaration]
 *
 */

extern void push(char);
extern char pop(void);
extern int is_empty(void);

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


