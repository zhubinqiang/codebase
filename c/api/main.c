#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*ApiFunction1)(void);
typedef void (*ApiFunction2)(int);
typedef void (*ApiFunction3)(const char*);

int main() {
    const char* vendorLibEnv = getenv("VENDOR_LIB");
    const char* vendorLib = vendorLibEnv ? vendorLibEnv : "default_vendor_library.so";

    void* handle = dlopen(vendorLib, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Failed to load library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    ApiFunction1 func1 = (ApiFunction1)dlsym(handle, "function1");
    ApiFunction2 func2 = (ApiFunction2)dlsym(handle, "function2");
    ApiFunction3 func3 = (ApiFunction3)dlsym(handle, "function3");
    char* error;
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Failed to locate functions: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    // 使用函数指针调用API函数
    func1();
    func2(123);
    func3("test string");

    // 释放库
    dlclose(handle);
    return EXIT_SUCCESS;
}

