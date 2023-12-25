
#include "VendorA.h"
#include <stdio.h>

void function1(void) {
    printf("Vendor A - Function 1\n");
}

void function2(int value) {
    printf("Vendor A - Function 2: %d\n", value);
}

void function3(const char* message) {
    printf("Vendor A - Function 3: %s\n", message);
}

