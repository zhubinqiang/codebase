#include <stdio.h>

typedef enum {
    STATE_IDLE,
    STATE_DRAWING,
    STATE_RENDERING
} State;

int main() {
    State currentState = STATE_IDLE;
    char input;

    while (1) {
        switch (currentState) {
            case STATE_IDLE:
                printf("Idle state: Waiting for input.\n");
                // 获取用户输入
                scanf(" %c", &input);
                if (input == 'q') {
                    // 如果用户按下了"q"键，则退出循环
                    printf("Exiting.\n");
                    return 0;
                } else {
                    currentState = STATE_DRAWING;
                }
                break;

            case STATE_DRAWING:
                printf("Drawing state: Drawing shapes.\n");
                currentState = STATE_RENDERING;
                break;

            case STATE_RENDERING:
                printf("Rendering state: Rendering scene.\n");
                currentState = STATE_IDLE;
                break;
        }
    }

    return 0;
}

