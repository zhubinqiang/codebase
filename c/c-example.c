/*
 * @file: c-example.c
 * @author: ZhuBinQiang <zhu.binqiang@163.com>
 * @create time: 2021-04-06 23:28:13
 * @last modified: 2021-04-06 23:28:13
 * @description:
 */
#include <stdio.h>

void if_statement() {
    int i = 1;
    if (i > 0) {
        printf("%d is a positive number\n", i);
    } else if (i < 0) {
        printf("%d is a nagitive number\n", i);
    } else {
        printf("%d is zero\n", i);
    }

    int x = 15;
    if (x > 0 && x < 10) {
        ;
    } else {
        printf("%d is out of range. \n", x);
    }

    if (x <= 0 || x >=10) {
        printf("%d is out of range. \n", x);
    }
}

void switch_statement(int day) {
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Thusday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Satuday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Illegal day number\n");
            break;
    }
}

void loop_statement() {
    int sum = 0;
    int i = 1;

    while(i <= 100) {
        sum += i;
        i++;
    }
    printf("while: 1 + 2 + 3 + ... + 100 = %d\n", sum);

    sum = 0;
    i = 1;
    for (i = 1; i <= 100; ++i) {
        sum += i;
    }
    printf("for: 1 + 2 + 3 + ... + 100 = %d\n", sum);

    sum = 0;
    i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 100);
    printf("do-while: 1 + 2 + 3 + ... + 100 = %d\n", sum);

    int flag;
    for (i = 2; i < 10; ++i) {
        flag = 0;
        for (int j = 2; j < i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        printf("%d is a prime number\n", i);
    }
}

#include <stdlib.h>
#include <time.h>
#define N 100
void array_statement() {
    // 4, 3, 2, 0, 0
    int count[5] = {4, 3, 2};

    // int count2[3] = {3, 2, 1};
    int count2[] = {3, 2, 1};
    printf("%p\n", count2);
    printf("%p\n", &count2[0]);

    int i;
    for (i = 0; i < 5; ++i) {
        printf("%d\t", count[i]);
    }
    printf("\n");


    int a[N];
    srand(time(NULL));
    for (i = 0; i < N; ++i) {
        a[i] = rand() % 10;
    }

    int b[10] = {0, }, j;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < N; ++j) {
            if (i == a[j]) {
                b[i] += 1;
            }
        }
    }

    for (i = 0; i < 10; ++i) {
        printf("%d: %d\n", i, b[i]);
    }
    printf("\n");

    for (i = 0; i < 10; ++i) {
        printf("%-2d", i);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        for (j = 0; j < 10; j++) {
            if (b[j] > 0) {
                printf("* ");
                b[j] = b[j] - 1;
            } else {
                printf("  ");
            }
        }
        printf("\n");

        int zero = 0;
        for (int k = 0; k < 10; k++) {
            if(b[k] == 0) {
                zero++;
            }
        }

        if(zero > 9) {
            break;
        }
    }


    // 2 dimensional Array
    // int two_dim_array[3][2] = {1, 2, 3, 4, 5};
    int two_dim_array[3][2] = { {1, 2}, {3, 4}, {5} };
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; j++) {
            printf("%-2d", two_dim_array[i][j]);
        }
        printf("\n");
    }
}


#include <string.h>
void handle_string() {
    char c = "Hello, world.\n"[0];
    printf("%c\n", c);

    // read-only
    // "Hello, world.\n"[0] = 'h';

    // str1 == str2
    char str1[10] = "Hello";
    char str2[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str1);
    printf("str1: %ld, %ld\n", sizeof(str1), strlen(str1));
    printf("str2: %ld, %ld\n", sizeof(str2), strlen(str2));
}

// struct start
struct complex_struct {
    double x;
    double y;
} z1, z2;

double complex_get_real_part(struct complex_struct z) {
    return z.x;
}

double complex_get_imaginary_part(struct complex_struct z) {
    return z.y;
}

void complex_show(struct complex_struct z) {
    if (z.y > 0) {
        printf("%f+%fi\n", z.x, z.y);
    } else {
        printf("%f%fi\n", z.x, z.y);
    }
}

#include <math.h>
double complex_get_modulus(struct complex_struct z) {
    return sqrt(z.x * z.x + z.y * z.y);
}

double complex_get_angle(struct complex_struct z) {
    double PI = acos(-1.0);
    if (z.x > 0) {
        return atan(z.y / z.x);
    } else {
        return atan(z.y / z.x) + PI;
    }
}

struct complex_struct complex_make_from_real_img(double x, double y) {
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}

struct complex_struct complex_add(struct complex_struct z1, struct complex_struct z2) {
    double x= complex_get_real_part(z1) + complex_get_real_part(z2);
    double y = complex_get_imaginary_part(z1) + complex_get_imaginary_part(z2);
    return complex_make_from_real_img(x, y);
}

void handle_struct() {
    struct complex_struct z3;
    z3.x = 3;
    z3.y = -5;
    if (z3.y > 0) {
        printf("z3 = %f+%fi\n", z3.x, z3.y);
    } else {
        printf("z3 = %f%fi\n", z3.x, z3.y);
    }

    struct complex_struct z4 = {1.734, 1};
    printf("z4 = %f+%fi\n", z4.x, z4.y);
    printf("modulus of z4 = %f\n", complex_get_modulus(z4));
    printf("angle of z4 = %f\n", complex_get_angle(z4));

    struct complex_struct z5 = complex_make_from_real_img(4, 3);
    printf("modulus of z5 = %f\n", complex_get_modulus(z5));

    struct complex_struct z6 = complex_add(z3, z5);
    complex_show(z6);
}
// struct end



// enum start
// start with 0 by default
enum SEASON {spring, summer, autumn, winter};

enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };

void handle_enum() {
    enum DAY day;
    day = SUN;
    printf("day = %d\n", day);

    int i;
    for (i = spring; i < winter; ++i) {
        printf("season = %d\t", i);
    }
    printf("\n");

    enum SEASON season = 2;
    switch (season) {
        case spring:
            printf("you like spring\n");
            break;
        case summer:
            printf("you like summer\n");
            break;
        case autumn:
            printf("you like autumn\n");
            break;
        case winter:
            printf("you like winter\n");
            break;
        default:
            printf("you don't like them\n");
            break;
    }
}

// enum end





// Variable Argument
// refer to: https://www.runoob.com/cprogramming/c-variable-arguments.html
// 使用 stdarg.h 头文件，该文件提供了实现可变参数功能的函数和宏
// 定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
// 在函数定义中创建一个 va_list 类型变量，该类型是在 stdarg.h 头文件中定义的。
// 使用 int 参数和 va_start 宏来初始化 va_list 变量为一个参数列表。宏 va_start 是在 stdarg.h 头文件中定义的。
// 使用 va_arg 宏和 va_list 变量来访问参数列表中的每个项。
// 使用宏 va_end 来清理赋予 va_list 变量的内存。
//
#include <stdarg.h>
int average(int num, ...) {
    va_list list;

    int sum = 0;
    int i;

    // 为 num 个参数初始化 valist
    va_start(list, num);

    for (i = 0; i < num; ++i) {
        sum += va_arg(list, int);
    }

    // 清理为 valist 保留的内存
    va_end(list);

    return sum / num;
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int greatest_common_divisor(int a, int b) {
    int max, min;
    // a > b ? max=a : max=b;
    if (a >= b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    if (max % min == 0) {
        return min;
    } else {
        return greatest_common_divisor(min, max%min);
    }
}

// recursive
void recursive() {
    int num = 6;
    printf("%d! = %d\n", num, factorial(num));

    int a = 6;
    int b = 8;
    printf("greatest common divisor of %d, %d = %d\n",
            a, b, greatest_common_divisor(a, b));
}

int main(int argc, char *argv[]) {
    // if_statement();
    // switch_statement(6);
    // loop_statement();
    array_statement();
    // handle_string();
    // handle_struct();
    // handle_enum();
    // recursive();
    // printf("Average of 1, 2, 3, 4, 5 = %d\n", average(5, 1, 2, 3, 4, 5));

    return 0;
}

