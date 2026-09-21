#include "Queue.h"
#include <iostream>

void Queue::enqueue(int value) { data.push_back(value); }

int Queue::dequeue() {
    if (data.empty()) throw std::out_of_range("Queue is empty");
    int value = data.front();
    data.pop_front();
    return value;
}

int Queue::front() const {
    if (data.empty()) throw std::out_of_range("Queue is empty");
    return data.front();
}

bool Queue::empty() const { return data.empty(); }

size_t Queue::size() const { return data.size(); }

void Queue::clear() { data.clear(); }

bool Queue::contains(int value) const {
    for (int v : data) if (v == value) return true;
    return false;
}

void Queue::print() const {
    std::cout << "Queue (front -> back): ";
    for (int v : data) std::cout << v << " ";
    std::cout << "\n";
}