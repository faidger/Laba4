class Stack:
    def __init__(self):
        self._data = []

    def push(self, value):
        self._data.append(value)

    def pop(self):
        if not self._data:
            raise IndexError("Stack is empty")
        return self._data.pop()

    def top(self):
        if not self._data:
            raise IndexError("Stack is empty")
        return self._data[-1]

    def empty(self):
        return not self._data

    def size(self):
        return len(self._data)

    def clear(self):
        self._data.clear()

    def contains(self, value):
        return value in self._data

    def __str__(self):
        return "Stack(top->bottom): " + " ".join(map(str, reversed(self._data)))
