#include "../headers/s21_array.h"

#include <gtest/gtest.h>

TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 10> a;
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(static_cast<int>(a.size()), 0);
}

TEST(ArrayTest, InitializerListConstructor) {
  s21::array<int, 10> a = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(static_cast<int>(a.size()), 6);
  EXPECT_EQ(a.front(), 1);
  EXPECT_EQ(a.back(), 6);
}

TEST(ArrayTest, CopyConstructor) {
  s21::array<int, 10> a1 = {1, 2, 3, 4, 5};
  s21::array<int, 10> a2(a1);
  EXPECT_EQ(static_cast<int>(a2.size()), 5);
  EXPECT_EQ(a2.front(), 1);
  EXPECT_EQ(a2.back(), 5);
}

TEST(ArrayTest, MoveConstructor) {
  s21::array<int, 10> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> a2(std::move(a1));
  EXPECT_EQ(static_cast<int>(a2.size()), 10);
  EXPECT_EQ(a2.front(), 1);
  EXPECT_EQ(a2.back(), 10);
  EXPECT_EQ(static_cast<int>(a1.size()), 0);
}

TEST(ArrayTest, MoveAssignmentOperator) {
  s21::array<int, 10> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> a2;
  a2 = std::move(a1);
  EXPECT_EQ(static_cast<int>(a2.size()), 10);
  EXPECT_EQ(a2.front(), 1);
  EXPECT_EQ(a2.back(), 10);
  EXPECT_EQ(static_cast<int>(a1.size()), 0);
}

TEST(ArrayTest, AtMethod_1) {
  s21::array<int, 10> a;
  a.fill(1);
  for (auto i = 0; i < 10; i++) {
    int value = a.at(i);
    EXPECT_EQ(value, 1);
  }
}

TEST(ArrayTest, AtMethod_2) {
  s21::array<int, 10> a;
  a.fill(1);
  EXPECT_THROW(a.at(-1), std::out_of_range);
}

TEST(ArrayTest, OperatorIndex) {
  s21::array<int, 10> a;
  a.fill(10);
  for (auto i = 0; i < 10; ++i) {
    EXPECT_EQ(a[i], 10);
  }
}

TEST(ArrayTest, FrontMethod) {
  s21::array<int, 3> a = {1, 2, 3};
  EXPECT_EQ(a.front(), 1);
}

TEST(ArrayTest, BackMethod) {
  s21::array<int, 3> a = {1, 2, 3};
  EXPECT_EQ(a.back(), 3);
}

TEST(ArrayTest, DataMethod) {
  s21::array<int, 10> a;
  a.fill(10);
  auto it = a.data();
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(*it, 10);
    ++it;
  }
}

TEST(ArrayTest, BeginMethod) {
  s21::array<int, 10> a;
  a.fill(10);
  auto it = a.begin();
  EXPECT_EQ(*it, 10);
  size_t count = 0;
  for (auto it = a.begin(); count != a.size(); ++it, ++count) {
    EXPECT_EQ(*it, 10);
  }
  EXPECT_EQ(count, a.size());
}

TEST(ArrayTest, EndMethod) {
  s21::array<int, 10> a;
  a.fill(10);
  size_t count = 0;
  for (auto it = a.begin(); it != a.end(); ++it, ++count) {
    EXPECT_EQ(*it, 10);
  }
  EXPECT_EQ(count, a.size());
}

TEST(ArrayTest, EmptyMethod) {
  s21::array<int, 10> a;
  EXPECT_TRUE(a.empty());
  a.fill(10);
  EXPECT_FALSE(a.empty());
}

TEST(ArrayTest, SizeMethod) {
  s21::array<int, 10> a;
  EXPECT_EQ(static_cast<int>(a.size()), 0);
  a.fill(10);
  EXPECT_EQ(static_cast<int>(a.size()), 10);
}

TEST(ArrayTest, MaxSizeMethod) {
  s21::array<int, 10> a;
  EXPECT_EQ(static_cast<int>(a.max_size()), 10);
}

TEST(ArrayTest, SwapMethod) {
  s21::array<int, 5> a = {1, 2, 3, 4, 5};
  s21::array<int, 5> b = {6, 7, 8, 9, 10};

  a.swap(b);

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(a[i], i + 6);
    EXPECT_EQ(b[i], i + 1);
  }
}

TEST(ArrayTest, FillMethod) {
  s21::array<int, 10> a;
  a.fill(10);
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(a[i], 10);
  }
  EXPECT_EQ(static_cast<int>(a.size()), 10);
}