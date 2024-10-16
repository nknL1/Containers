#include "../headers/s21_vector.h"

#include <gtest/gtest.h>

TEST(VectorTest, DefaultConstructor) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(static_cast<int>(v.capacity()), 0);
}

TEST(VectorTest, SizeConstructor) {
  s21::vector<int> v(10);
  EXPECT_EQ(static_cast<int>(v.size()), 10);
}

TEST(VectorTest, InitalazerListConstructor) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
  EXPECT_EQ(v.back(), 5);
  EXPECT_EQ(static_cast<int>(v.size()), 5);
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(static_cast<int>(v2.size()), 3);
  EXPECT_EQ(v2.front(), 1);
  EXPECT_EQ(v2.back(), 3);
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(static_cast<int>(v2.size()), 3);
  EXPECT_EQ(v2.front(), 1);
  EXPECT_EQ(v2.back(), 3);
  EXPECT_EQ(static_cast<int>(v1.size()), 0);
}

TEST(VectorTest, MoveAssignmentOperator) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(static_cast<int>(v2.size()), 10);
  EXPECT_EQ(v2.front(), 1);
  EXPECT_EQ(v2.back(), 10);
  EXPECT_EQ(static_cast<int>(v1.size()), 0);
}

TEST(VectorTest, AtMethod) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(1), 2);
  EXPECT_EQ(v.at(2), 3);
}

TEST(VectorTest, OperatorSquareBrackets) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, FrontAndBack) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.front(), 1);
  EXPECT_EQ(v.back(), 3);
}

TEST(VectorTest, Empty) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  // v.push_back(1);
  // EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Size) {
  s21::vector<int> v;
  EXPECT_EQ(static_cast<int>(v.size()), 0);
  v.push_back(1);
  EXPECT_EQ(static_cast<int>(v.size()), 1);
  v.push_back(2);
  EXPECT_EQ(static_cast<int>(v.size()), 2);
}

TEST(VectorTest, Capacity) {
  s21::vector<int> v;
  EXPECT_EQ(static_cast<int>(v.capacity()), 0);
  v.push_back(1);
  EXPECT_EQ(static_cast<int>(v.capacity()), 1);
  v.reserve(10);
  EXPECT_EQ(static_cast<int>(v.capacity()), 10);
}

TEST(VectorTest, Reserve) {
  s21::vector<int> v;
  v.reserve(10);
  EXPECT_EQ(static_cast<int>(v.capacity()), 10);
  v.push_back(1);
  EXPECT_EQ(static_cast<int>(v.size()), 1);
  v.reserve(20);
  EXPECT_EQ(static_cast<int>(v.capacity()), 20);
}

TEST(VectorTest, ShrinkToFit) {
  s21::vector<int> v;
  v.reserve(10);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.shrink_to_fit();
  EXPECT_EQ(static_cast<int>(v.capacity()), 3);
}

TEST(VectorTest, Clear) {
  s21::vector<int> v = {1, 2, 3};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(static_cast<int>(v.size()), 0);
}

TEST(VectorTest, Insert) {
  s21::vector<int> v = {1, 2, 3};
  v.insert(v.begin() + 1, 4);
  EXPECT_EQ(static_cast<int>(v.size()), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 4);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 3);
}

TEST(VectorTest, Erase) {
  s21::vector<int> v = {1, 2, 3};
  v.erase(v.begin() + 1);
  EXPECT_EQ(static_cast<int>(v.size()), 2);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, PushBack) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(static_cast<int>(v.size()), 1);
  v.push_back(2);
  EXPECT_EQ(static_cast<int>(v.size()), 2);
  v.push_back(3);
  EXPECT_EQ(static_cast<int>(v.size()), 3);
}

TEST(VectorTest, PopBack) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(static_cast<int>(v.size()), 2);
  v.pop_back();
  EXPECT_EQ(static_cast<int>(v.size()), 1);
  v.pop_back();
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Swap) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};
  v1.swap(v2);
  EXPECT_EQ(static_cast<int>(v1.size()), 3);
  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[1], 5);
  EXPECT_EQ(v1[2], 6);
  EXPECT_EQ(static_cast<int>(v2.size()), 3);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> v = {1, 2, 3};
  v.insert_many(v.begin() + 1, 4, 5, 6);
  EXPECT_EQ(static_cast<int>(v.size()), 6);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 4);
  EXPECT_EQ(v[2], 5);
  EXPECT_EQ(v[3], 6);
  EXPECT_EQ(v[4], 2);
  EXPECT_EQ(v[5], 3);
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> v = {1, 2, 3};
  v.insert_many_back(4, 5, 6);
  EXPECT_EQ(static_cast<int>(v.size()), 6);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], 5);
  EXPECT_EQ(v[5], 6);
}