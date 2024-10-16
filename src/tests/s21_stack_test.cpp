#include "../headers/s21_stack.h"

#include <gtest/gtest.h>

TEST(StackTest, DefaultConstructor) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, InitializerListConstructor) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_EQ(static_cast<int>(stack.size()), 3);
  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, CopyConstructor) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2(stack1);
  EXPECT_EQ(static_cast<int>(stack2.size()), 3);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, MoveConstructor) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2(std::move(stack1));
  EXPECT_EQ(static_cast<int>(stack2.size()), 3);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, CopyAssignmentOperator) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2;
  stack2 = stack1;
  EXPECT_EQ(static_cast<int>(stack2.size()), 3);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, MoveAssignmentOperator) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2;
  stack2 = std::move(stack1);
  EXPECT_EQ(static_cast<int>(stack2.size()), 3);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, Top) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, Empty) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_FALSE(stack.empty());
  stack.pop();
  stack.pop();
  stack.pop();
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Size) {
  s21::stack<int> stack;
  EXPECT_EQ(static_cast<int>(stack.size()), 0);
  stack.push(1);
  EXPECT_EQ(static_cast<int>(stack.size()), 1);
  stack.push(2);
  EXPECT_EQ(static_cast<int>(stack.size()), 2);
  stack.pop();
  EXPECT_EQ(static_cast<int>(stack.size()), 1);
}

TEST(StackTest, InsertManyFront) {
  s21::stack<int> stack;
  stack.insert_many_front(1, 2, 3);
  EXPECT_EQ(static_cast<int>(stack.size()), 3);
  EXPECT_EQ(stack.top(), 3);
}
