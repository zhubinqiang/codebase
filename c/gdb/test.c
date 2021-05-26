/*
 * @file: test.c
 * @author: ZhuBinQiang <zhu.binqiang@163.com>
 * @create time: 2021-05-21 16:41:21
 * @last modified: 2021-05-21 16:41:21
 * @description:
 */
#include <stdio.h>
#include "hello.h"

void f1() {
    char *str = "This is f1";
    printf("%s\n", str);
}

void f2() {
    int i = 0;
    int s = 0;

    i = i + 2;
    i = i + 3;

    for (i = 1; i < 5; ++i) {
        s += i;
    }
    printf("S = %d\n", s);
}

int main(int argc, char *argv[]) {
    int i = 2;
    int j = 4;
    int s = i + j;
    printf("s = %d\n", s);
    f1();
    f2();
    f3();

    return 0;
}


