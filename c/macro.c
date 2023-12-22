#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int max() {
    int x = 5, y = 10;
    // 当预处理器处理到MAX(x, y)时, 会进行文本替换
    // 将MAX(x, y)替换为((x) > (y) ? (x) : (y))
    //
    // int max_val = ((x) > (y) ? (x) : (y));
    int max_val = MAX(x, y);
    printf("max = %d\n", max_val);
    return 0;
}

// 定义宏：检查指针是否为空
#define CHECK_NULL_PTR(ptr)                \
    if ((ptr) == NULL) {                   \
        fprintf(stderr, "Null pointer detected in %s at line %d.\n", __FILE__, __LINE__); \
        return;                            \
    }

// 示例使用这个宏的函数
void process(int *p) {
    CHECK_NULL_PTR(p);
    // 如果指针不是NULL，继续函数的其他部分
    // ... 这里是函数的其他代码 ...
    printf("Good\n");
}

int main(int argc, char *argv[]) {
    int *q = NULL;
    int a = 1;
    int *p = &a;
    process(p);
    process(q);

    max();
    return 0;
}
