#include "VendorB.h"
#include <stdio.h>

void function1(void) {
    printf("Vendor B - Function 1\n");
}

void function2(int value) {
    printf("Vendor B - Function 2: %d\n", value);
}

void function3(const char* message) {
    printf("Vendor B - Function 3: %s\n", message);
}


