#include <stdio.h>

typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_PAUSED,
    STATE_STOPPED
} State;

State currentState = STATE_IDLE;

void handleEvent(State state, int event) {
    switch (state) {
        case STATE_IDLE:
            if (event == 1) {
                currentState = STATE_RUNNING;
                printf("Transition: IDLE -> RUNNING\n");
            }
            break;
        case STATE_RUNNING:
            if (event == 2) {
                currentState = STATE_PAUSED;
                printf("Transition: RUNNING -> PAUSED\n");
            } else if (event == 3) {
                currentState = STATE_STOPPED;
                printf("Transition: RUNNING -> STOPPED\n");
            }
            break;
        case STATE_PAUSED:
            if (event == 4) {
                currentState = STATE_RUNNING;
                printf("Transition: PAUSED -> RUNNING\n");
            } else if (event == 3) {
                currentState = STATE_STOPPED;
                printf("Transition: PAUSED -> STOPPED\n");
            }
            break;
        case STATE_STOPPED:
            if (event == 1) {
                currentState = STATE_RUNNING;
                printf("Transition: STOPPED -> RUNNING\n");
            }
            break;
        default:
            break;
    }
}

int main() {
    // 模拟事件序列
    int events[] = {1, 2, 4, 3, 1};

    int numEvents = sizeof(events) / sizeof(int);

    // 处理事件序列
    for (int i = 0; i < numEvents; i++) {
        handleEvent(currentState, events[i]);
    }

    return 0;
}

