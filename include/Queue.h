#pragma once
#include <deque>
#include <stdexcept>

class Queue {
private:
    std::deque<int> data;

public:
    void enqueue(int value);
    int dequeue();
    int front() const;
    bool empty() const;
    size_t size() const;
    void clear();
    bool contains(int value) const;
    void print() const;
};