
/*
 * 在计算机网络中，滑动窗口算法是一种流控制算法，用来管理在两个网络设备之间传输数据的速率，
 * 以防止发送方发送数据过快以至于接收方来不及处理。以下是一个使用C语言的简单模拟实现：
 *
*/

#include <stdio.h>
#include <string.h>

#define WINDOW_SIZE 4 // 假设窗口大小为4个包

// 模拟的数据包
typedef struct {
    int id;     // 包的ID
    char data;  // 包含的数据
} Packet;

// 发送窗口结构
typedef struct {
    Packet packets[WINDOW_SIZE]; // 窗口内的数据包
    int head;                    // 窗口头的位置
    int tail;                    // 窗口尾的位置
} SlidingWindow;

// 初始化窗口
void initWindow(SlidingWindow *window) {
    window->head = 0;
    window->tail = -1;  // 窗口为空时tail指向-1
}

// 检查窗口是否已满
int isWindowFull(SlidingWindow *window) {
    return ((window->tail + 1) % WINDOW_SIZE) == window->head;
}

// 发送数据包
void sendPacket(SlidingWindow *window, Packet packet) {
    if (!isWindowFull(window)) {
        window->tail = (window->tail + 1) % WINDOW_SIZE;
        window->packets[window->tail] = packet;
        printf("发送数据包: %d\n", packet.id);
    } else {
        printf("窗口已满, 无法发送数据包: %d\n", packet.id);
    }
}

// 确认数据包（模拟接收方确认）
void acknowledgePacket(SlidingWindow *window, int ackId) {
    while (window->head != ((window->tail + 1) % WINDOW_SIZE)) {
        if (window->packets[window->head].id == ackId) {
            printf("确认数据包: %d\n", ackId);
            window->head = (window->head + 1) % WINDOW_SIZE;
            return;
        }
        window->head = (window->head + 1) % WINDOW_SIZE;
    }
}

int main() {
    SlidingWindow window;
    initWindow(&window);

    // 发送数据包
    for (int id = 1; id <= 10; ++id) {
        Packet packet = {id, 'A' + id - 1}; // 创建数据包
        sendPacket(&window, packet);

        // 模拟确认，为简化我们每发送一个包就确认一个包
        if (id % WINDOW_SIZE == 0) {
            acknowledgePacket(&window, id - WINDOW_SIZE + 1);
        }window.packets[window.tail] = packet;
    }

    // 模拟剩余确认
    while (window.head != ((window.tail + 1) % WINDOW_SIZE)) {
        acknowledgePacket(&window, window.packets[window.head].id);
    }

    return 0;
}

