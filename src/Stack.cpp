#include "Stack.h"
#include <iostream>

void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (data.empty()) throw std::out_of_range("Stack is empty");
    int value = data.back();
    data.pop_back();
    return value;
}

int Stack::top() const {
    if (data.empty()) throw std::out_of_range("Stack is empty");
    return data.back();
}

bool Stack::empty() const { return data.empty(); }

size_t Stack::size() const { return data.size(); }

void Stack::clear() { data.clear(); }

bool Stack::contains(int value) const {
    for (int v : data) if (v == value) return true;
    return false;
}

void Stack::print() const {
    std::cout << "Stack (top -> bottom): ";
    for (auto it = data.rbegin(); it != data.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}
