#include <stdio.h>

int readstr(unsigned char *str, int len) {
    printf("===========================\n");
    printf("len = %d\n", len);

    printf("[");
    for (int i=0; i<len; i++) {
        if (str[0] == '\0') {
            printf("\\0");
        } else {
            printf("%c", str[i]);
        }
    }
    printf("]\n");
    printf("===========================\n");

    return len;
}

int f1() {
    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;


    // Open the file
    FILE * file = fopen("uvtemplate.bmp", "rb");
    if (!file)
    {
        printf("Image could not be openedn");
        return 1;
    }

    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP filen");
        return 2;
    }

    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP filen");
        return 3;
    }

    // Read ints from the byte array
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    printf("dataPos = %d\n", dataPos);
    printf("imageSize = %d\n", imageSize);
    printf("width = %d\n", width);
    printf("height = %d\n", height);

    // printf("header = %s\n", header);
    readstr(header, sizeof(header));

    return 0;
}

int main(int argc, char *argv[]) {
    f1();
    return 0;
}

