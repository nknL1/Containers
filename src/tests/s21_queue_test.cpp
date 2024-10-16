#include "../headers/s21_queue.h"

#include <gtest/gtest.h>

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(static_cast<int>(q.size()), 0);
}

TEST(QueueTest, InitializerListConstructor) {
  s21::queue<int> q = {1, 2, 3};
  EXPECT_EQ(static_cast<int>(q.size()), 3);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 3);
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> q1 = {1, 2, 3};
  s21::queue<int> q2(q1);
  EXPECT_EQ(static_cast<int>(q2.size()), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> q1 = {1, 2, 3};
  s21::queue<int> q2(std::move(q1));
  EXPECT_EQ(static_cast<int>(q2.size()), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);
  EXPECT_TRUE(q1.empty());
}

TEST(QueueTest, CopyAssignmentOperator) {
  s21::queue<int> q1 = {1, 2, 3};
  s21::queue<int> q2;
  q2 = q1;
  EXPECT_EQ(static_cast<int>(q2.size()), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> q1 = {1, 2, 3};
  s21::queue<int> q2;
  q2 = std::move(q1);
  EXPECT_EQ(static_cast<int>(q2.size()), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);
  EXPECT_TRUE(q1.empty());
}

TEST(QueueTest, Front) {
  s21::queue<int> q = {1, 2, 3};
  EXPECT_EQ(q.front(), 1);
}

TEST(QueueTest, Back) {
  s21::queue<int> q = {1, 2, 3};
  EXPECT_EQ(q.back(), 3);
}

TEST(QueueTest, Empty) {
  s21::queue<int> q;
  EXPECT_TRUE(q.empty());
  q.push(1);
  EXPECT_FALSE(q.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> q;
  EXPECT_EQ(static_cast<int>(q.size()), 0);
  q.push(1);
  EXPECT_EQ(static_cast<int>(q.size()), 1);
  q.push(2);
  EXPECT_EQ(static_cast<int>(q.size()), 2);
  q.pop();
  EXPECT_EQ(static_cast<int>(q.size()), 1);
}

TEST(QueueTest, Push) {
  s21::queue<int> q;
  q.push(1);
  EXPECT_EQ(static_cast<int>(q.size()), 1);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 1);
  q.push(2);
  EXPECT_EQ(static_cast<int>(q.size()), 2);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 2);
}

TEST(QueueTest, Pop) {
  s21::queue<int> q = {1, 2, 3};
  q.pop();
  EXPECT_EQ(static_cast<int>(q.size()), 2);
  EXPECT_EQ(q.front(), 2);
  q.pop();
  EXPECT_EQ(static_cast<int>(q.size()), 1);
  EXPECT_EQ(q.front(), 3);
  q.pop();
  EXPECT_TRUE(q.empty());
}

TEST(QueueTest, Swap) {
  s21::queue<int> q1 = {1, 2, 3};
  s21::queue<int> q2 = {4, 5};
  q1.swap(q2);
  EXPECT_EQ(static_cast<int>(q1.size()), 2);
  EXPECT_EQ(q1.front(), 4);
  EXPECT_EQ(q1.back(), 5);
  EXPECT_EQ(static_cast<int>(q2.size()), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);
}

TEST(QueueTest, InsertManyBack) {
  s21::queue<int> q;
  q.insert_many_back(1, 2, 3, 4, 5);
  EXPECT_EQ(static_cast<int>(q.size()), 5);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 5);
}
