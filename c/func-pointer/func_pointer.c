#include <stdio.h>

// void (*ApiFunction2)(int); 这部分是声明了一个名为`ApiFunction2`的函数指针，该指针指向一个接受一个`int`类型参数并返回`void`的函数。
// 在这个声明前加上`typedef`关键字，这告诉编译器我们要创建一个新的类型名称`ApiFunction2`，它就是指向上述类型的函数的指针。
typedef void (*ApiFunction2)(int);

// 假设有一个符合该函数指针类型的函数
void exampleFunction(int value) {
    printf("Value: %d\n", value);
}

int add(int a, int b) {
    return a + b;
}

int main() {
    // 声明一个ApiFunction2类型的变量，并将其初始化为指向exampleFunction
    ApiFunction2 funcPtr = exampleFunction;

    // 使用函数指针调用函数
    funcPtr(42);  // 输出将会是 "Value: 42"


    // 声明函数指针并指向add函数
    int (*funcPtr2)(int, int) = add;

    // 使用函数指针调用函数
    int result = funcPtr2(2, 3);
    printf("Result: %d\n", result);

    return 0;
}



