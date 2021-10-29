#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void cat(char *path) {
    char ch;
    FILE *file = NULL;
    file = fopen(path, "r");
    if(NULL != file) {
        printf("Yes\n");
        ch = fgetc(file);
        while(ch != EOF) {
            putchar(ch);
            ch = fgetc(file);
        }
    } else {
        printf("%s Not found\n", path);
    }
    free(file);
}



