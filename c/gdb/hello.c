#include <stdio.h>
#include <stdlib.h>

struct complex_stu {
    double x;
    double y;
};

void show_complex(struct complex_stu* z) {
    if (z->y > 0) {
        printf("%f + %fi\n", z->x, z->y);
    } else {
        printf("%f - %fi\n", z->x, -z->y);
    }
}

void f4() {
    struct complex_stu *z1 = (struct complex_stu*)malloc(sizeof(struct complex_stu));
    z1->x = 3.0;
    z1->y = -4.0;
    show_complex(z1);
    free(z1);
}

void f3(int low, int hight) {
    int i = 0;
    int s = 0;
    for (i = low; i < hight; ++i) {
        s += i;
    }
    printf("f3: S = %d\n", s);
}

