#include <stdio.h>
#include <stdlib.h>

// refer to https://wangdoc.com/clang/file.html
void f1() {
    FILE *fp = fopen("Makefile", "r");
    if (NULL == fp) {
        printf("Can't open\n");
        // exit(1);
        exit(EXIT_FAILURE);
    }

    printf("===============================\n");
    char ch = fgetc(fp);
    printf("%c\n", ch);

    long file_pos = ftell(fp);
    printf("*********%ld*******\n", file_pos);
    printf("===============================\n");

    fseek(fp, 0L, SEEK_SET);
    int c;
    while((c = getc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("===============================\n");

    // 定位到文件倒数第10个字节
    fseek(fp, -10L, SEEK_END);
    int size = 1024;
    char s[1024];
    while(NULL != fgets(s, size, fp)) {
        printf("%s", s);
    }
    printf("===============================\n");

    fclose(fp);
}

void f2() {
    FILE *fp = fopen("output.txt", "w");
    if (NULL == fp) {
        printf("Can't open\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Hello\n");
    fclose(fp);
}

void f3() {
    FILE *fp = freopen("output-reopen.txt", "w", stdout);
    if (NULL == fp) {
        printf("Can't open\n");
        exit(EXIT_FAILURE);
    }

    printf("Hello\n");
    fclose(fp);
}


int main(void) {
    f1();
    // f2();
    // f3();
    return 0;
}

