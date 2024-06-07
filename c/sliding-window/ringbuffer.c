#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];  // 存储数据的数组
    int head;                 // 缓冲区队首的索引
    int tail;                 // 缓冲区队尾的索引
    int count;                // 缓冲区中元素的数量
} RingBuffer;

void initRingBuffer(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int isFull(RingBuffer* rb) {
    return rb->count == BUFFER_SIZE;
}

int isEmpty(RingBuffer* rb) {
    return rb->count == 0;
}

void addElement(RingBuffer *rb, int element) {
    if (isFull(rb)) {
        printf("Ring buffer is full.\n");
        return;
    }

    rb->buffer[rb->head] = element;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;
}

int removeElement(RingBuffer *rb) {
    if (isEmpty(rb)) {
        printf("Ring buffer is empty.\n");
        return -1;  // 返回一个错误值，表示缓冲区为空
    }

    int element = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;
    return element;
}

int main() {
    RingBuffer rb;
    initRingBuffer(&rb);

    // 添加元素到缓冲区
    for (int i = 0; i < BUFFER_SIZE; i++) {
        addElement(&rb, i);
    }

    // 移除并打印所有元素
    while (!isEmpty(&rb)) {
        int element = removeElement(&rb);
        printf("%d ", element);
    }
    printf("\n");

    return 0;
}


