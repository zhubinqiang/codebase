extern char stack[512];
extern int top;

void f1(int i) {
    i + i;
}

char pop(void) {
    // f1(top);
    return stack[top--];
}


