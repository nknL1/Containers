#include "../headers/s21_list.h"

#include <gtest/gtest.h>

#include <list>

bool listsEqual(s21::list<int> L1, std::list<int> L2) {
  if (L1.size() != L2.size()) {
    return false;
  }
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  for (; it_L1 != L1.end(); ++it_L1, ++it_L2) {
    if (*it_L1 != *it_L2) {
      return false;
    }
  }
  return true;
}

TEST(LIST, DEFAULT_CONSTRUCTOR) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, NSIZE_CONSTRUCTOR) {
  s21::list<int> L1(3);
  std::list<int> L2(3);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, LIST_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, COPY_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2(L1);
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(L3);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, MOVE_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2(std::move(L1));
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(std::move(L3));
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, SIZE_DEFAULT_CONTRUCTOR) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(LIST, SIZE_NSIZE_CONSTRUCTOR) {
  s21::list<int> L1(3);
  std::list<int> L2(3);
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(LIST, SIZE_LIST_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(LIST, SIZE_COPY_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3, 4, 5, 6, 7};
  s21::list<int> L2(L1);
  std::list<int> L3 = {1, 2, 3, 4, 5, 6, 7};
  std::list<int> L4(L3);
  ASSERT_EQ(L2.size(), L4.size());
}

TEST(LIST, SIZE_MOVE_CONSTRUCTOR) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2(std::move(L1));
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4(std::move(L3));
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(LIST, EMPTY_NSIZE_CONSTRUCTOR) {
  s21::list<int> L1(1);
  std::list<int> L2(1);
  ASSERT_EQ(L1.empty(), L2.empty());
  s21::list<int> L3(0);
  std::list<int> L4(0);
  ASSERT_EQ(L3.empty(), L4.empty());
  s21::list<int> L5(0);
  std::list<int> L6(0);
  L5.push_back(0);
  L6.push_back(0);
  ASSERT_EQ(L5.empty(), L6.empty());
  L5.pop_front();
  L6.pop_front();
  ASSERT_EQ(L5.empty(), L6.empty());
}

TEST(LIST, EMPTY_LIST_CONSTRUCTOR) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  ASSERT_EQ(L1.empty(), L2.empty());
  s21::list<int> L3 = {1};
  std::list<int> L4 = {1};
  ASSERT_EQ(L3.empty(), L4.empty());
  L1.push_back(1);
  L2.push_back(1);
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(LIST, EMPTY_COPY_CONSTRUCTOR) {
  s21::list<int> L1;
  s21::list<int> L2(L1);
  std::list<int> L3;
  std::list<int> L4(L3);
  ASSERT_EQ(L2.empty(), L4.empty());
  s21::list<int> L5 = {1};
  s21::list<int> L6(L5);
  std::list<int> L7 = {1};
  std::list<int> L8(L7);
  ASSERT_EQ(L6.empty(), L8.empty());
}

TEST(LIST, EMPTY_MOVE_CONSTRUCTOR) {
  s21::list<int> L1;
  s21::list<int> L2(std::move(L1));
  std::list<int> L3;
  std::list<int> L4(std::move(L3));
  ASSERT_EQ(L1.empty(), L3.empty());
  ASSERT_EQ(L2.empty(), L4.empty());
}

TEST(LIST, SWAP_ONE_IS_EMPTY) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
  s21::list<int> L5 = {};
  s21::list<int> L6 = {4, 5, 6};
  std::list<int> L7 = {};
  std::list<int> L8 = {4, 5, 6};
  L5.swap(L6);
  L7.swap(L8);
  ASSERT_EQ(listsEqual(L5, L7), true);
  ASSERT_EQ(listsEqual(L6, L8), true);
}

TEST(LIST, SWAP_BOTH_IS_EMPTY) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {};
  std::list<int> L3 = {};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, SWAP_SAME_LENGTH) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, SWAP_DIFFERENT_LENGTH) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
  s21::list<int> L5 = {1, 2, 3};
  s21::list<int> L6 = {4, 5, 6, 128, 40};
  std::list<int> L7 = {1, 2, 3};
  std::list<int> L8 = {4, 5, 6, 128, 40};
  L5.swap(L6);
  L7.swap(L8);
  ASSERT_EQ(listsEqual(L5, L7), true);
  ASSERT_EQ(listsEqual(L6, L8), true);
}

TEST(LIST, REVERSE_5_ELEMENTS) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, REVERSE_4_ELEMENTS) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, REVERSE_1_ELEMENT) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, REVERSE_0_ELEMENTS) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, INSERT_START) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
  s21::list<int> L3 = {1};
  std::list<int> L4 = {1};
  s21::list<int>::iterator it_L3 = L3.begin();
  std::list<int>::iterator it_L4 = L4.begin();
  L3.insert(it_L3, 128);
  L4.insert(it_L4, 128);
  ASSERT_EQ(listsEqual(L3, L4), true);
}

TEST(LIST, INSERT_MIDDLE) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, INSERT_END) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, INSERT_CYCLIC_SHIFT) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L1;
  ++it_L2;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, INSERT_EMPTY_LIST) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, MAX_SIZE) {
  s21::list<int> L1;
  std::list<int> L2;
  EXPECT_EQ(L1.max_size(), (L2.max_size()));
}

TEST(LIST, ERASE_FIRST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, ERASE_LAST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = --L1.end();
  std::list<int>::iterator it_L2 = --L2.end();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, ERASE_MIDDLE) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, SORT) {
  s21::list<int> L1 = {9, 2, 3, 1, 4};
  std::list<int> L2 = {9, 2, 3, 1, 4};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
  s21::list<int> L3 = {1};
  std::list<int> L4 = {1};
  L3.sort();
  L4.sort();
  ASSERT_EQ(listsEqual(L3, L4), true);
  s21::list<int> L5 = {};
  std::list<int> L6 = {};
  L5.sort();
  L6.sort();
  ASSERT_EQ(listsEqual(L5, L6), true);
}

TEST(LIST, SORT_STRING) {
  s21::list<std::string> L1 = {"abcd", "abcdef", "abc"};
  std::list<std::string> L2 = {"abcd", "abcdef", "abc"};
  L1.sort();
  L2.sort();
  s21::list<std::string>::iterator it_L1 = L1.begin();
  std::list<std::string>::iterator it_L2 = L2.begin();
  for (; it_L2 != L2.end(); ++it_L2, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L2);
  }
}

TEST(LIST, SORT_SORTED) {
  s21::list<int> L1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, MERGE_IDENTICAL) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {1, 2, 3, 4, 5};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {1, 2, 3, 4, 5};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, MERGE_ONE_LIST_EMPTY) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {5, 4, 3, 2, 1};
  std::list<int> L3 = {};
  std::list<int> L4 = {5, 4, 3, 2, 1};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
  s21::list<int> L5 = {1, 2, 3, 4, 5};
  s21::list<int> L6 = {};
  std::list<int> L7 = {1, 2, 3, 4, 5};
  std::list<int> L8 = {};
  L5.merge(L6);
  L7.merge(L8);
  ASSERT_EQ(listsEqual(L5, L7), true);
  ASSERT_EQ(listsEqual(L6, L8), true);
}

TEST(LIST, MERGE_SORTED_LISTS) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {6, 7, 8, 9, 10};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
  s21::list<int> L5 = {1, 3, 5, 7};
  s21::list<int> L6 = {2, 4, 6, 8};
  std::list<int> L7 = {1, 3, 5, 7};
  std::list<int> L8 = {2, 4, 6, 8};
  L5.merge(L6);
  L7.merge(L8);
  ASSERT_EQ(listsEqual(L5, L7), true);
  ASSERT_EQ(listsEqual(L6, L8), true);
}

TEST(LIST, MERGE_STRING) {
  s21::list<std::string> L1 = {"abc", "abcd", "abcdef"};
  s21::list<std::string> L2 = {"ab", "abcde"};
  std::list<std::string> L3 = {"abc", "abcd", "abcdef"};
  std::list<std::string> L4 = {"ab", "abcde"};
  L1.merge(L2);
  L3.merge(L4);
  s21::list<std::string>::iterator it_L1 = L1.begin();
  s21::list<std::string>::iterator it_L2 = L2.begin();
  std::list<std::string>::iterator it_L3 = L3.begin();
  std::list<std::string>::iterator it_L4 = L4.begin();
  for (; it_L3 != L3.end(); ++it_L3, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L3);
  }
  for (; it_L4 != L4.end(); ++it_L4, ++it_L2) {
    ASSERT_EQ(*it_L2, *it_L4);
  }
}

TEST(LIST, UNIQUE_SORTED_LIST) {
  s21::list<int> L1 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  std::list<int> L2 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, UNIQUE_UNSORTED_LIST) {
  s21::list<int> L1 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  std::list<int> L2 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, UNIQUE_EMPTY_LIST) {
  s21::list<int> L1 = {};
  std::list<int> L2 = {};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, UNIQUE_ONE) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, SPLICE_FIRST) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6, 1, 2, 3};
  s21::list<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(LIST, SPLICE_SECOND) {
  s21::list<int> L1 = {1, 2};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 4, 5, 6, 2};
  s21::list<int>::const_iterator it = ++L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(LIST, SPLICE_TO_EMPTY_LIST) {
  s21::list<int> L1 = {};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6};
  s21::list<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(LIST, SPLICE_FROM_EMPTY_LIST) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 2, 3};
  s21::list<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(LIST, FRONT_EMPTY_LIST) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.front(), L2.front());
}

TEST(LIST, FRONT_3_ELEMENTS) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.front(), L2.front());
}

TEST(LIST, BACK_EMPTY_LIST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.back(), L2.back());
}

TEST(LIST, BACK_3_ELEMENTS) {
  s21::list<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.back(), L2.back());
}

TEST(LIST, PUSH_FRONT) {
  s21::list<int> L1;
  std::list<int> L2;
  L1.push_front(1);
  L2.push_front(1);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, PUSH_BACK) {
  s21::list<int> L1;
  std::list<int> L2;
  L1.push_back(1);
  L2.push_back(1);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, POP_FRONT) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_front();
  L2.pop_front();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, POP_BACK) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_back();
  L2.pop_back();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, DOUBLE_PLUS_BEFORE) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_MINUS_BEFORE) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = --L1.begin();
  std::list<int>::iterator it_L2 = --L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_PLUS_AFTER) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin()++;
  std::list<int>::iterator it_L2 = L2.begin()++;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_MINUS_AFTER) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin()--;
  std::list<int>::iterator it_L2 = L2.begin()--;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DEREFERENCE_EXISTING_LIST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
  s21::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {1, 2, 3};
  s21::list<int>::iterator it_L3 = L3.begin();
  std::list<int>::iterator it_L4 = L4.begin();
  *it_L3 = 128;
  *it_L4 = 128;
  ASSERT_EQ(*it_L3, *it_L4);
}

TEST(LIST, DEREFERENCE_NOT_EXISTING_LIST) {
  try {
    s21::list<int>::iterator it_L1;
    *it_L1;
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(LIST, NOT_EQUAL) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() != L1.begin(), L2.begin() != L2.begin());
}

TEST(LIST, EQUAL) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() == L1.begin(), L2.begin() == L2.begin());
}

TEST(LIST, DOUBLE_PLUS_BEFORE_CONST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::const_iterator it_L1 = ++L1.cbegin();
  std::list<int>::const_iterator it_L2 = ++L2.cbegin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_MINUS_BEFORE_CONST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::const_iterator it_L1 = --L1.cbegin();
  std::list<int>::const_iterator it_L2 = --L2.cbegin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_PLUS_AFTER_CONST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::const_iterator it_L1 = L1.cbegin()++;
  std::list<int>::const_iterator it_L2 = L2.cbegin()++;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DOUBLE_MINUS_AFTER_CONST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::const_iterator it_L1 = L1.cbegin()--;
  std::list<int>::const_iterator it_L2 = L2.cbegin()--;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DEREFERENCE_EXISTING_LIST_CONST) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::list<int>::const_iterator it_L1 = L1.cbegin();
  std::list<int>::const_iterator it_L2 = L2.cbegin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(LIST, DEREFERENCE_NOT_EXISTING_LIST_CONST) {
  try {
    s21::list<int>::const_iterator it_L1;
    *it_L1;
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(LIST, EMPLACE) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 4, 5, 6, 2, 3};
  L1.emplace(++L1.begin(), 4, 5, 6);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, EMPLACE_BACK) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6};
  L1.emplace_back(4, 5, 6);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, EMPLACE_FRONT) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {4, 5, 6, 1, 2, 3};
  L1.emplace_front(4, 5, 6);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, EQUAL_COPY) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = L2;
  L3 = L4;
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, EQUAL_MOVE) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = std::move(L2);
  L3 = std::move(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, INSERT_MANY) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list.begin();
  ++our_it;
  our_list.insert_many(our_it, 7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

TEST(LIST, INSERT_MANY_FRONT) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_front(7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

TEST(LIST, INSERT_MANY_BACK) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list.begin();
  our_list.insert_many_back(7, 8, 9);
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
  ++our_it;
  EXPECT_EQ(*our_it, 3);
  ++our_it;
  EXPECT_EQ(*our_it, 4);
  ++our_it;
  EXPECT_EQ(*our_it, 5);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
}
