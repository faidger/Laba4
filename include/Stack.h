#pragma once
#include <vector>
#include <cstddef>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value);
    int pop();
    int top() const;
    bool empty() const;
    size_t size() const;
    void clear();
    bool contains(int value) const;
    void print() const;
};
