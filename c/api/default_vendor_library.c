#include "default_vendor_library.h"
#include <stdio.h>

void function1(void) {
    printf("default_vendor_library - Function 1\n");
}

void function2(int value) {
    printf("default_vendor_library - Function 2: %d\n", value);
}

void function3(const char* message) {
    printf("default_vendor_library - Function 3: %s\n", message);
}




