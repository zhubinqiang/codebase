
static char stack[512];
static int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop(void) {
    return stack[top--];
}

int is_empty() {
    return top == -1;
}


