#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"

#define MAXBUFSIZE 1024

void pwd(void) {
    char buf[MAXBUFSIZE];
    getcwd(buf, MAXBUFSIZE);
    printf("\n");
    printf("%s\n", buf);
}



