#include <stdio.h>
#include <stdlib.h>

// 顶点结构体
typedef struct Vertex {
   float x, y, z;
} Vertex;

// VAO和VBO结构体
typedef struct {
   int vao;
   int vbo;
   Vertex *vertices;
} VertexData;

// 创建VAO
int createVAO() {
   int vao;
   glGenVertexArrays(1, &vao);
   glBindVertexArray(vao);
   return vao;
}

// 创建VBO
int createVBO() {
   int vbo;
   glGenBuffers(1, &vbo);
   glBindBuffer(GL_ARRAY_BUFFER, vbo);
   return vbo;
}

// 绑定VAO
void bindVAO(int vao) {
   glBindVertexArray(vao);
}

// 绑定VBO
void bindVBO(int vbo) {
   glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

// 解绑VAO和VBO
void unbindVAO() {
   glBindVertexArray(0);
}

void unbindVBO() {
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// 初始化顶点数据
VertexData *initVertexData() {
   VertexData *data = (VertexData *)malloc(sizeof(VertexData));
   data->vao = createVAO();
   data->vbo = createVBO();
   data->vertices = (Vertex *)malloc(4 * sizeof(Vertex));
   return data;
}

int main() {
   // 初始化顶点数据
   VertexData *vertexData = initVertexData();
   vertexData->vertices[0] = (Vertex){-0.5f, -0.5f, 0.0f};
   vertexData->vertices[1] = (Vertex){ 0.5f, -0.5f, 0.0f};
   vertexData->vertices[2] = (Vertex){ 0.5f,  0.5f, 0.0f};
   vertexData->vertices[3] = (Vertex){-0.5f,  0.5f, 0.0f};

   // 绑定VAO和VBO
   bindVAO(vertexData->vao);
   bindVBO(vertexData->vbo);

   // 假设我们在这里设置顶点属性，例如位置属性
   // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

   // 假设我们在这里绘制图形
   // glDrawArrays(GL_TRIANGLES, 0, 3);

   // 解绑VAO和VBO
   unbindVAO();
   unbindVBO();

   // 释放资源
   free(vertexData->vertices);
   free(vertexData);

   return 0;
}



