#include <stdio.h>
#define MAX_LINE 1024

int cat(char *path) {
    FILE *file; ;
    if ((file = fopen(path, "r")) == NULL) {
        printf("Open %s Falied!\n", path);
        return 128;
    }

    char buff[255];
    int i = 0;
    while (!feof(file)) {
        fgets(buff, MAX_LINE, file);
        i++;
        printf("%d: %s", i, buff);
    }
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    cat(argv[1]);
    return 0;
}


