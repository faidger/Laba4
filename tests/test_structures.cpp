#include <gtest/gtest.h>
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

// ---------- Stack ----------
TEST(StackTest, PushPopTop) {
    Stack s;
    s.push(1); s.push(2); s.push(3);
    EXPECT_EQ(s.top(), 3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.size(), 2u);
}

TEST(StackTest, EmptyPopThrows) {
    Stack s;
    EXPECT_THROW(s.pop(), std::out_of_range);
    EXPECT_THROW(s.top(), std::out_of_range);
}

TEST(StackTest, ClearAndContains) {
    Stack s;
    s.push(5); s.push(7);
    EXPECT_TRUE(s.contains(5));
    EXPECT_FALSE(s.contains(6));
    s.clear();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0u);
}

// ---------- Queue ----------
TEST(QueueTest, EnqueueDequeue) {
    Queue q;
    q.enqueue(10); q.enqueue(20);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.dequeue(), 10);
    EXPECT_EQ(q.size(), 1u);
}

TEST(QueueTest, EmptyDequeueThrows) {
    Queue q;
    EXPECT_THROW(q.dequeue(), std::out_of_range);
    EXPECT_THROW(q.front(), std::out_of_range);
}

TEST(QueueTest, ContainsAndClear) {
    Queue q;
    q.enqueue(3); q.enqueue(4);
    EXPECT_TRUE(q.contains(4));
    EXPECT_FALSE(q.contains(5));
    q.clear();
    EXPECT_TRUE(q.empty());
}

// ---------- BinaryTree ----------
TEST(BinaryTreeTest, InsertAndContains) {
    BinaryTree t;
    t.insert(5); t.insert(3); t.insert(7);
    EXPECT_TRUE(t.contains(5));
    EXPECT_TRUE(t.contains(3));
    EXPECT_TRUE(t.contains(7));
    EXPECT_FALSE(t.contains(10));
    EXPECT_EQ(t.size(), 3u);
}

TEST(BinaryTreeTest, RemoveLeafAndRoot) {
    BinaryTree t;
    t.insert(5); t.insert(3); t.insert(7);
    EXPECT_TRUE(t.remove(3));
    EXPECT_FALSE(t.contains(3));
    EXPECT_TRUE(t.remove(5));
    EXPECT_EQ(t.size(), 1u);
    EXPECT_FALSE(t.remove(100));
}

TEST(BinaryTreeTest, EmptyAndClear) {
    BinaryTree t;
    EXPECT_TRUE(t.empty());
    t.insert(1); t.insert(2);
    t.clear();
    EXPECT_TRUE(t.empty());
    EXPECT_EQ(t.size(), 0u);
}

TEST(StackTest, SizeAfterOps) {
    Stack s;
    EXPECT_TRUE(s.empty());
    s.push(1); s.push(2); s.push(3); s.push(4);
    EXPECT_EQ(s.size(), 4u);
    s.pop(); s.pop();
    EXPECT_EQ(s.size(), 2u);
}

TEST(QueueTest, SizeAfterOps) {
    Queue q;
    EXPECT_TRUE(q.empty());
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    EXPECT_EQ(q.size(), 3u);
    q.dequeue();
    EXPECT_EQ(q.size(), 2u);
}

TEST(BinaryTreeTest, RemoveWithTwoChildren) {
    BinaryTree t;
    t.insert(10); t.insert(5); t.insert(15);
    t.insert(3); t.insert(7); t.insert(12); t.insert(20);
    EXPECT_TRUE(t.remove(5));
    EXPECT_FALSE(t.contains(5));
    EXPECT_TRUE(t.contains(3));
    EXPECT_TRUE(t.contains(7));
    EXPECT_EQ(t.size(), 6u);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
