#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESOURCES 10

// 资源类型，例如一个简单的字符串
typedef struct Resource {
    char data[256];
} Resource;

// 资源管理器，存储指向资源的指针
Resource* resourceManager[MAX_RESOURCES] = {NULL};

// 创建资源，并返回一个句柄
int createResource(const char* data) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (resourceManager[i] == NULL) {
            Resource* res = (Resource*)malloc(sizeof(Resource));
            if (res == NULL) {
                return -1; // 分配失败，返回无效句柄
            }
            strncpy(res->data, data, sizeof(res->data));
            resourceManager[i] = res;
            return i; // 返回句柄（这里是数组的索引）
        }
    }
    return -1; // 无可用资源，返回无效句柄
}

// 根据句柄释放资源
void releaseResource(int handle) {
    if (handle >= 0 && handle < MAX_RESOURCES && resourceManager[handle] != NULL) {
        free(resourceManager[handle]);
        resourceManager[handle] = NULL;
    }
}

// 根据句柄获取资源
Resource* getResource(int handle) {
    if (handle >= 0 && handle < MAX_RESOURCES) {
        return resourceManager[handle];
    }
    return NULL; // 无效句柄或资源不存在
}

int main() {
    // 创建一个资源
    int resHandle = createResource("Hello, Handle!");
    if (resHandle == -1) {
        printf("Failed to create resource.\n");
        return 1;
    }

    // 使用句柄获取资源
    Resource* res = getResource(resHandle);
    if (res != NULL) {
        printf("Resource Data: %s\n", res->data);
    }

    // 释放资源
    releaseResource(resHandle);

    return 0;
}


