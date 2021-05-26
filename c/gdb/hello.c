/*
 * @file: hello.c
 * @author: Zhu, BinQiang <bin.qiangx.zhu@intel.com>
 * @create time: 2021-05-24 16:52:53
 * @last modified: 2021-05-24 16:52:53
 * @description:
 */
#include <stdio.h>

void f3() {
    int i = 0;
    int s = 0;
    for (i = 1; i < 5; ++i) {
        s += i;
    }
    printf("f3: S = %d\n", s);
}

