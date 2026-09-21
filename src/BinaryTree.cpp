#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr), count(0) {}

BinaryTree::~BinaryTree() { destroy(root); }

void BinaryTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

BinaryTree::Node* BinaryTree::insert(Node* node, int value) {
    if (!node) { count++; return new Node(value); }
    if (value < node->value) node->left = insert(node->left, value);
    else if (value > node->value) node->right = insert(node->right, value);
    return node;
}

void BinaryTree::insert(int value) { root = insert(root, value); }

BinaryTree::Node* BinaryTree::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

BinaryTree::Node* BinaryTree::remove(Node* node, int value, bool& removed) {
    if (!node) return nullptr;
    if (value < node->value) {
        node->left = remove(node->left, value, removed);
    } else if (value > node->value) {
        node->right = remove(node->right, value, removed);
    } else {
        removed = true;
        if (!node->left) {
            Node* r = node->right;
            delete node;
            return r;
        }
        if (!node->right) {
            Node* l = node->left;
            delete node;
            return l;
        }
        Node* minNode = findMin(node->right);
        node->value = minNode->value;
        bool dummy = false;
        node->right = remove(node->right, minNode->value, dummy);
    }
    return node;
}

bool BinaryTree::remove(int value) {
    bool removed = false;
    root = remove(root, value, removed);
    if (removed) count--;          // уменьшаем ровно один раз
    return removed;
}

bool BinaryTree::contains(Node* node, int value) const {
    if (!node) return false;
    if (value == node->value) return true;
    return value < node->value ? contains(node->left, value)
                               : contains(node->right, value);
}

bool BinaryTree::contains(int value) const { return contains(root, value); }

void BinaryTree::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->value << " ";
    inorder(node->right);
}

void BinaryTree::print() const {
    std::cout << "Tree (inorder): ";
    inorder(root);
    std::cout << "\n";
}

void BinaryTree::clear() { destroy(root); root = nullptr; count = 0; }

size_t BinaryTree::size() const { return count; }
bool BinaryTree::empty() const { return count == 0; }