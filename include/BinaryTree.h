#pragma once
#include <cstddef>

class BinaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t count;

    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value, bool& removed);
    Node* findMin(Node* node);
    bool contains(Node* node, int value) const;
    void inorder(Node* node) const;
    void destroy(Node* node);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    bool remove(int value);
    bool contains(int value) const;
    void print() const;
    void clear();
    size_t size() const;
    bool empty() const;
};