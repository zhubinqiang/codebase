#!/usr/bin/env python3

class EventDispatcher:
    def __init__(self):
        self._event_handlers = {}

    def register_handler(self, event_name, handler):
        """注册事件处理函数"""
        if event_name not in self._event_handlers:
            self._event_handlers[event_name] = []
        self._event_handlers[event_name].append(handler)

    def unregister_handler(self, event_name, handler):
        """注销事件处理函数"""
        if event_name in self._event_handlers:
            self._event_handlers[event_name].remove(handler)
            if not self._event_handlers[event_name]:  # 如果该事件没有处理函数了，则删除该事件
                del self._event_handlers[event_name]

    def dispatch(self, event_name, *args, **kwargs):
        """分发事件"""
        handlers = self._event_handlers.get(event_name, [])
        for handler in handlers:
            handler(*args, **kwargs)

# 示例使用

def handle_event1(message):
    print(f"Handling event 1 with message: {message}")

def handle_event2(data):
    print(f"Handling event 2 with data: {data}")


def main():
    # 创建一个事件调度器实例
    dispatcher = EventDispatcher()

    # 注册事件处理函数
    dispatcher.register_handler("event1", handle_event1)
    dispatcher.register_handler("event2", handle_event2)

    # 分发事件
    dispatcher.dispatch("event1", message="Hello, World!")
    dispatcher.dispatch("event2", data={"key": "value"})

    # 注销事件处理函数
    dispatcher.unregister_handler("event1", handle_event1)

    # 再次分发事件1，将看到没有任何输出，因为对应的处理函数已被注销
    dispatcher.dispatch("event1", message="This will not be handled.")

if __name__ == "__main__":
    main()


