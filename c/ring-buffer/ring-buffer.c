#include <stdio.h>
#include <stdbool.h>

/*
 *
 *
初始状态（空缓冲区）：
[ ][ ][ ][ ][ ][ ][ ][ ]
 ↑
头指针和尾指针都在这里

写入数据'A'到缓冲区：
[A][ ][ ][ ][ ][ ][ ][ ]
   ↑
  头指针
 ↑
尾指针

继续写入数据'B'和'C'：
[A][B][C][ ][ ][ ][ ][ ]
         ↑
        头指针
 ↑
尾指针

读取数据'A'：
[ ][B][C][ ][ ][ ][ ][ ]
   ↑  ↑
  尾指针 头指针

继续写入数据'D'，'E'，'F'，当头指针到达数组的末端时，它会回绕到数组的开始：
[ ][B][C][D][E][F][G][H]
 ↑                          ↑
尾指针                    头指针

这时候缓冲区已满，如果尝试写入更多数据将无法进行，因为头指针将会追上尾指针。

现在如果我们读取数据'B'和'C'：
[ ][ ][ ][D][E][F][G][H]
       ↑
      尾指针
                          ↑
                        头指针

此时，尾指针已经移动了，缓冲区中又有了空间可以写入新的数据。如果我们写入数据'I'和'J'：
[I][ ][ ][D][E][F][G][H]
   ↑   ↑
  头指针
      尾指针

*/


#define BUFFER_SIZE 8  // 缓冲区的大小

// 环形缓冲区的结构体
typedef struct {
    int buffer[BUFFER_SIZE];  // 存储数据的数组
    int head;                 // 指向下一个要写入的位置
    int tail;                 // 指向下一个要读取的位置
} RingBuffer;

// 初始化环形缓冲区
void ringBufferInit(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
}

// 向环形缓冲区写入数据
bool ringBufferWrite(RingBuffer *rb, int data) {
    int next = (rb->head + 1) % BUFFER_SIZE;
    if (next == rb->tail) {  // 缓冲区已满
        return false;
    }
    rb->buffer[rb->head] = data;
    rb->head = next;
    return true;
}

// 从环形缓冲区读取数据
bool ringBufferRead(RingBuffer *rb, int *data) {
    if (rb->head == rb->tail) {  // 缓冲区为空
        return false;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    return true;
}

int main() {
    RingBuffer rb;
    ringBufferInit(&rb);  // 初始化环形缓冲区

    // 写入数据到环形缓冲区
    for (int i = 0; i < BUFFER_SIZE - 1; i++) {
        if (ringBufferWrite(&rb, i)) {
            printf("写入: %d\n", i);
        } else {
            printf("缓冲区已满，无法写入 %d\n", i);
        }
    }

    // 读取数据从环形缓冲区
    int value;
    while (ringBufferRead(&rb, &value)) {
        printf("读取: %d\n", value);
    }

    // 再次尝试写入
    if (ringBufferWrite(&rb, 100)) {
        printf("写入: %d\n", 100);
    } else {
        printf("缓冲区已满，无法写入 %d\n", 100);
    }

    return 0;
}

