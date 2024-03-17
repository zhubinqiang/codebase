#include <stdio.h>

// 定义顶点缓冲区对象结构体
typedef struct {
    int id;  // 缓冲区对象的ID
    int target;  // 绑定的目标
} VertexBufferObject;

// 模拟OpenGL的绑定操作
void glBindBuffer(int target, VertexBufferObject* vbo) {
    vbo->target = target;
    printf("VBO %d 已绑定到目标 %d\n", vbo->id, vbo->target);
}

// 模拟OpenGL的数据复制操作
void glBufferData(VertexBufferObject* vbo, int size, void* data, int usage) {
    printf("向VBO %d 中复制数据，大小为 %d 字节，用途为 %d\n", vbo->id, size, usage);
}

int main() {
    // 创建一个VBO对象
    VertexBufferObject vbo = {1, 0};  // 假设VBO的ID为1

    // 模拟绑定操作
    glBindBuffer(1, &vbo);

    // 模拟数据复制操作
    int vertices[] = {1, 2, 3, 4, 5};
    glBufferData(&vbo, sizeof(vertices), vertices, 0);

    return 0;
}


