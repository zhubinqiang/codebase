#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>

void glGenBuffersToFile(GLuint* buffer, FILE** file) {
    glGenBuffers(1, buffer);
    *file = fopen("buffer.bin", "wb");
}

void glBindBufferToFile(GLuint buffer, FILE* file) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
}

void glBufferDataWithVertices(FILE* file, GLfloat* vertices, GLsizei size) {
    fwrite(vertices, sizeof(GLfloat), size, file);
}

void glDeleteBufferAndCloseFile(GLuint buffer, FILE* file) {
    fclose(file);
    glDeleteBuffers(1, &buffer);
}

int main() {
    // 模拟顶点数据
    GLfloat vertices[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    GLsizei verticesSize = sizeof(vertices) / sizeof(GLfloat);

    // 创建文件指针和缓冲区对象
    FILE* file;
    GLuint vertexBuffer;

    // 生成缓冲区对象并绑定文件
    glGenBuffersToFile(&vertexBuffer, &file);

    // 绑定缓冲区对象到OpenGL上下文
    glBindBufferToFile(vertexBuffer, file);

    // 将顶点数据写入文件缓冲区
    glBufferDataWithVertices(file, vertices, verticesSize);

    // 使用缓冲区进行渲染...

    // 删除缓冲区对象并关闭文件
    glDeleteBufferAndCloseFile(vertexBuffer, file);

    return 0;
}

