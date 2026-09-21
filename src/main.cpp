#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>

void printHelp() {
    std::cout <<
        "\nКоманды:\n"
        "  stack push <v> | pop | top | print | size | clear | contains <v>\n"
        "  queue enq <v>  | deq | front | print | size | clear | contains <v>\n"
        "  tree insert <v>| remove <v> | print | size | clear | contains <v>\n"
        "  help | exit\n";
}

int main() {
    Stack stack;
    Queue queue;
    BinaryTree tree;
    std::string cmd;

    printHelp();
    while (std::cout << "> ", std::cin >> cmd && cmd != "exit") {
        try {
            if (cmd == "stack") {
                std::string op; std::cin >> op;
                if (op == "push") { int v; std::cin >> v; stack.push(v); }
                else if (op == "pop") std::cout << "pop: " << stack.pop() << "\n";
                else if (op == "top") std::cout << "top: " << stack.top() << "\n";
                else if (op == "print") stack.print();
                else if (op == "size") std::cout << stack.size() << "\n";
                else if (op == "clear") stack.clear();
                else if (op == "contains") { int v; std::cin >> v; std::cout << (stack.contains(v) ? "yes" : "no") << "\n"; }
            } else if (cmd == "queue") {
                std::string op; std::cin >> op;
                if (op == "enq") { int v; std::cin >> v; queue.enqueue(v); }
                else if (op == "deq") std::cout << "deq: " << queue.dequeue() << "\n";
                else if (op == "front") std::cout << "front: " << queue.front() << "\n";
                else if (op == "print") queue.print();
                else if (op == "size") std::cout << queue.size() << "\n";
                else if (op == "clear") queue.clear();
                else if (op == "contains") { int v; std::cin >> v; std::cout << (queue.contains(v) ? "yes" : "no") << "\n"; }
            } else if (cmd == "tree") {
                std::string op; std::cin >> op;
                if (op == "insert") { int v; std::cin >> v; tree.insert(v); }
                else if (op == "remove") { int v; std::cin >> v; std::cout << (tree.remove(v) ? "removed" : "not found") << "\n"; }
                else if (op == "print") tree.print();
                else if (op == "size") std::cout << tree.size() << "\n";
                else if (op == "clear") tree.clear();
                else if (op == "contains") { int v; std::cin >> v; std::cout << (tree.contains(v) ? "yes" : "no") << "\n"; }
            } else if (cmd == "help") {
                printHelp();
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }
    return 0;
}