#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

void glGenAndBindBuffer(FILE** file) {
    // *file = fopen("buffer.bin", "wb");
    *file = fopen("buffer.bin", "w");
}

void glBufferDataWithVertices(FILE* file, Vec3* vertices, size_t size) {
    fwrite(vertices, sizeof(Vec3), size, file);
}

void glDeleteBuffer(FILE* file) {
    fclose(file);
}

int main() {
    // 模拟顶点数据
    Vec3 vertices[] = {{1.0f, 2.0f, 3.0f},
                       {4.0f, 5.0f, 6.0f}};

    size_t verticesSize = sizeof(vertices) / sizeof(Vec3);

    // 创建文件指针
    FILE* file;

    // 创建缓冲区
    glGenAndBindBuffer(&file);

    // 将顶点数据写入缓冲区
    glBufferDataWithVertices(file, vertices, verticesSize);

    // 使用缓冲区进行渲染...

    // 删除缓冲区
    glDeleteBuffer(file);

    return 0;
}

