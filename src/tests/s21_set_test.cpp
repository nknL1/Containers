#include "../headers/s21_set.h"

#include <gtest/gtest.h>

TEST(SET, CONSTRUCTOR_TEST_1) {
  s21::set<int> s21_set_int;
  s21::set<double> s21_set_double;
  s21::set<std::string> s21_set_string;

  EXPECT_EQ(static_cast<int>(s21_set_int.size()), 0);
  EXPECT_EQ(s21_set_int.root->root, nullptr);

  EXPECT_EQ(static_cast<double>(s21_set_double.size()), 0);
  EXPECT_EQ(s21_set_double.root->root, nullptr);

  EXPECT_EQ(static_cast<int>(s21_set_string.size()), 0);
  EXPECT_EQ(s21_set_string.root->root, nullptr);
}

TEST(SET, CONSTRUCTOR_TEST_2) {
  s21::set<double> s21_set = {2.3, 55.5, 88.};

  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);

  EXPECT_EQ(s21_set.root->root->key, 55.5);
  EXPECT_EQ(s21_set.root->root->left->key, 2.3);
  EXPECT_EQ(s21_set.root->root->right->key, 88.);
}

TEST(SET, CONSTRUCTOR_TEST_3) {
  s21::set<int> s21_set = {1, 4, 7, 11, 41, 17};

  EXPECT_EQ(static_cast<int>(s21_set.size()), 6);

  EXPECT_EQ(s21_set.root->root->key, 4);
  EXPECT_EQ(s21_set.root->root->left->key, 1);
  EXPECT_EQ(s21_set.root->root->right->key, 11);
  EXPECT_EQ(s21_set.root->root->right->left->key, 7);
  EXPECT_EQ(s21_set.root->root->right->right->key, 41);
  EXPECT_EQ(s21_set.root->root->right->right->left->key, 17);
}

TEST(SET, CONSTRUCTOR_TEST_4) {
  s21::set<int> s21_set = {1, 4, 7, 11, 41, 17, 1, 4};

  EXPECT_EQ(static_cast<int>(s21_set.size()), 6);

  EXPECT_EQ(s21_set.root->root->key, 4);
  EXPECT_EQ(s21_set.root->root->left->key, 1);
  EXPECT_EQ(s21_set.root->root->right->key, 11);
  EXPECT_EQ(s21_set.root->root->right->left->key, 7);
  EXPECT_EQ(s21_set.root->root->right->right->key, 41);
  EXPECT_EQ(s21_set.root->root->right->right->left->key, 17);
}

TEST(SET, CONSTRUCTOR_TEST_5) {
  s21::set<std::string> s21_set = {"first", "second", "third"};
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, CONSTRUCTOR_TEST_6) {
  s21::set<std::string> s21_set = {"first", "second", "third",
                                   "first", "second", "third"};
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, CONSTRUCTOR_TEST_7) {
  s21::set<int> s21_set_ref = {1, 4, 7, 11, 41, 17};
  s21::set<int> s21_set_res(s21_set_ref);
  EXPECT_EQ(s21_set_res.size(), s21_set_ref.size());
}

TEST(SET, CONSTRUCTOR_TEST_8) {
  s21::set<std::string> s21_set_ref = {"first", "second", "third",
                                       "four",  "five",   "six"};

  s21::set<std::string> s21_set_res(s21_set_ref);
  EXPECT_EQ(s21_set_res.size(), s21_set_ref.size());
}

TEST(SET, CONSTRUCTOR_TEST_9) {
  s21::set<double> s21_set_ref = {1.4, 2.77, 3.9};
  s21::set<double> s21_set_res = std::move(s21_set_ref);
  EXPECT_EQ(static_cast<int>(s21_set_res.size()), 3);
}

TEST(SET, CONSTRUCTOR_TEST_10) {
  s21::set<std::string> s21_set_ref = {"first", "second", "third",
                                       "four",  "five",   "six"};
  s21::set<std::string> s21_set_res = std::move(s21_set_ref);
  EXPECT_EQ(static_cast<int>(s21_set_res.size()), 6);
}

TEST(SET, INSERT_TEST_1) {
  s21::set<int> s21_set;
  std::pair<s21::set<int>::iterator, bool> insert1 = s21_set.insert(9);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::set<int>::iterator, bool> insert4 = s21_set.insert(23);
  EXPECT_EQ(insert4.first.node->key, 23);
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::set<int>::iterator, bool> insert5 = s21_set.insert(98);
  EXPECT_EQ(insert5.first.node->key, 98);
  EXPECT_EQ(insert5.second, 1);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, INSERT_TEST_2) {
  s21::set<std::string> s21_set;
  std::pair<s21::set<std::string>::iterator, bool> insert1 =
      s21_set.insert("first");
  EXPECT_EQ(insert1.first.node->key, "first");
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::set<std::string>::iterator, bool> insert2 =
      s21_set.insert("second");
  EXPECT_EQ(insert2.first.node->key, "second");
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::set<std::string>::iterator, bool> insert3 =
      s21_set.insert("third");
  EXPECT_EQ(insert3.first.node->key, "third");
  EXPECT_EQ(insert3.second, 1);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, INSERT_TEST_3) {
  s21::set<double> s21_set;
  std::pair<s21::set<double>::iterator, bool> insert1 = s21_set.insert(9.8);
  EXPECT_EQ(insert1.first.node->key, 9.8);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::set<double>::iterator, bool> insert2 = s21_set.insert(3.14);
  EXPECT_EQ(insert2.first.node->key, 3.14);
  EXPECT_EQ(insert2.second, 1);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 2);
}

TEST(SET, BEGIN_TEST_1) {
  s21::set<double> s21_set = {9.8, 42.8, 3.14, 1.11, 2.12};
  auto min_value = s21_set.begin();
  EXPECT_EQ(min_value.node->key, 1.11);
}

TEST(SET, BEGIN_TEST_2) {
  s21::set<std::string> s21_set = {"first", "hee", "second", "third",
                                   "hee-hee"};
  auto min_value = s21_set.begin();
  EXPECT_EQ(min_value.node->key, "first");
}

TEST(SET, BEGIN_TEST_3) {
  s21::set<int> s21_set = {5, 8, 15, -3, 0};
  auto min_value = s21_set.begin();
  EXPECT_EQ(min_value.node->key, -3);
}

TEST(SET, BEGIN_TEST_4) {
  s21::set<int> s21_set{};
  EXPECT_EQ(s21_set.begin().node, s21_set.root->fake);
}

TEST(SET, BEGIN_TEST_5) {
  s21::set<double> s21_set = {8.88};
  auto min_value = s21_set.begin();
  EXPECT_EQ(min_value.node->key, 8.88);
}

TEST(SET, END_TEST_1) {
  s21::set<double> s21_set = {-5.56, 84.1, 0, 88.88, 77.7};
  auto end = s21_set.end();
  --end;
  EXPECT_EQ(end.node->key, 88.88);
}

TEST(SET, END_TEST_2) {
  s21::set<std::string> s21_set = {"first", "hee", "third", "second",
                                   "hee-hee"};
  auto end = s21_set.end();
  --end;
  EXPECT_EQ(end.node->key, "third");
}

TEST(SET, END_TEST_3) {
  s21::set<int> s21_set = {5, 10, -4, -8, 88};
  EXPECT_EQ(s21_set.end().node, s21_set.root->fake);
}

TEST(SET, END_TEST_4) {
  s21::set<double> s21_set;
  EXPECT_EQ(s21_set.end().node, s21_set.root->fake);
}

TEST(SET, END_TEST_5) {
  s21::set<std::string> s21_set = {"first"};
  auto end = s21_set.end();
  --end;
  EXPECT_EQ(end.node->key, "first");
}

TEST(SET, END_TEST_6) {
  s21::set<int> s21_set = {8};
  auto max_value = s21_set.end();
  EXPECT_EQ(max_value.node, s21_set.root->fake);
}

TEST(SET, EMPTY_TEST_1) {
  s21::set<double> s21_set = {3.14, -5.15, 8, 99};
  EXPECT_EQ(s21_set.empty(), 0);
}

TEST(SET, EMPTY_TEST_2) {
  s21::set<int> s21_set;
  EXPECT_EQ(s21_set.empty(), 1);
}

TEST(SET, SWAP_TEST_1) {
  s21::set<double> s21_set_ref = {3.8, -5};
  s21::set<double> s21_set_res = {4.2, 8.8, 15};
  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 3U);
  EXPECT_EQ(s21_set_ref.begin().node->key, 4.2);

  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(s21_set_res.begin().node->key, -5);
}

TEST(SET, SWAP_TEST_2) {
  s21::set<int> s21_set_ref = {3, 8};
  s21::set<int> s21_set_res;
  s21_set_ref.swap(s21_set_res);
  EXPECT_EQ(s21_set_ref.size(), 0U);
  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(s21_set_res.begin().node->key, 3);
  auto end = s21_set_res.end();
  --end;
  EXPECT_EQ(end.node->key, 8);
}

TEST(SET, SWAP_TEST_3) {
  s21::set<int> s21_set_ref;
  s21::set<int> s21_set_res = {3, -5, 8};
  s21_set_ref.swap(s21_set_res);
  EXPECT_EQ(s21_set_ref.size(), 3U);
  EXPECT_EQ(s21_set_ref.begin().node->key, -5);
  auto end = s21_set_ref.end();
  --end;
  EXPECT_EQ(end.node->key, 8);
  EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(SET, SWAP_TEST_4) {
  s21::set<double> s21_set_ref;
  s21::set<double> s21_set_res;
  s21_set_ref.swap(s21_set_res);
  EXPECT_EQ(s21_set_ref.size(), 0U);
  EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(SET, CONTAINS_TEST_1) {
  s21::set<double> s21_set = {3.14, 88.8};
  EXPECT_EQ(s21_set.contains(3.14), true);
  EXPECT_EQ(s21_set.contains(88.8), true);
  EXPECT_EQ(s21_set.contains(888.7), false);
}

TEST(SET, CONTAINS_TEST_2) {
  s21::set<int> s21_set_ref = {3, 8};
  s21::set<int> s21_set_res;
  s21_set_ref.swap(s21_set_res);
  EXPECT_EQ(s21_set_ref.size(), 0U);
  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(s21_set_ref.contains(3), false);
  EXPECT_EQ(s21_set_ref.contains(8), false);

  EXPECT_EQ(s21_set_res.contains(3), true);
  EXPECT_EQ(s21_set_res.contains(8), true);
}

TEST(SET, CONTAINS_TEST_3) {
  s21::set<std::string> s21_set_ref;
  s21::set<std::string> s21_set_res = {"pair1", "pair2", "pair3"};
  EXPECT_EQ(static_cast<int>(s21_set_ref.size()), 0);
  EXPECT_EQ(static_cast<int>(s21_set_res.size()), 3);
  s21_set_ref.swap(s21_set_res);
  EXPECT_EQ(static_cast<int>(s21_set_ref.size()), 3);
  EXPECT_EQ(s21_set_ref.contains("pair1"), true);
  EXPECT_EQ(s21_set_ref.contains("pair2"), true);
  EXPECT_EQ(s21_set_ref.contains("pair3"), true);
  EXPECT_EQ(static_cast<int>(s21_set_res.size()), 0);
  EXPECT_EQ(s21_set_res.contains("pair1"), false);
  EXPECT_EQ(s21_set_res.contains("pair2"), false);
  EXPECT_EQ(s21_set_res.contains("pair3"), false);
}

TEST(SET, CONTAINS_TEST_4) {
  s21::set<double> s21_set;
  EXPECT_EQ(s21_set.size(), 0U);
  EXPECT_EQ(s21_set.contains(12.4457), false);
}

TEST(SET, MERGE_TEST_1) {
  s21::set<int> s21_set_int_ref{3, -5, 8};
  s21::set<int> s21_set_int_res{7, 0, -9};
  s21_set_int_res.merge(s21_set_int_ref);
  EXPECT_EQ(static_cast<int>(s21_set_int_res.size()), 6);
}

TEST(SET, MERGE_TEST_2) {
  s21::set<int> s21_set_int_ref{8, -3, 0};
  s21::set<int> s21_set_int_res;
  s21_set_int_res.merge(s21_set_int_ref);
  EXPECT_EQ(static_cast<int>(s21_set_int_res.size()), 3);
}

TEST(SET, MERGE_TEST_3) {
  s21::set<double> s21_set_int_ref;
  s21::set<double> s21_set_int_res{3.14, 0, 8.88};
  EXPECT_EQ(static_cast<int>(s21_set_int_res.size()), 3);
}

TEST(SET, MERGE_TEST_4) {
  s21::set<std::string> s21_set_int_ref = {"pair1", "pair2", "pair3", "pair4"};
  s21::set<std::string> s21_set_int_res = {"pair5", "pair6"};
  s21_set_int_res.merge(s21_set_int_ref);
  EXPECT_EQ(static_cast<int>(s21_set_int_res.size()), 6);
}

TEST(SET, ERASE_TEST_1) {
  s21::set<std::string> s21_set;
  s21_set.insert("pair1");
  s21_set.insert("pair2");
  s21_set.insert("pair3");
  s21_set.insert("pair4");
  s21_set.insert("pair5");
  auto pos = s21_set.begin();
  EXPECT_EQ(s21_set.contains("pair1"), 1);
  s21_set.erase(pos);
  EXPECT_EQ(s21_set.contains("pair1"), 0);
}

TEST(SET, ERASE_TEST_2) {
  s21::set<double> s21_set;
  s21_set.insert(3.14);
  s21_set.insert(0);
  s21_set.insert(-5);
  s21_set.insert(88.8);
  s21_set.insert(7.1);
  auto pos = s21_set.begin();
  ++pos;
  EXPECT_EQ(s21_set.contains(0), 1);
  s21_set.erase(pos);
  EXPECT_EQ(s21_set.contains(0), 0);
}

TEST(SET, ERASE_TEST_3) {
  s21::set<int> s21_set;
  s21_set.insert(-5);
  s21_set.insert(0);
  s21_set.insert(8);
  s21_set.insert(11);
  s21_set.insert(14);
  auto pos = s21_set.begin();
  ++pos;
  ++pos;
  EXPECT_EQ(s21_set.contains(8), 1);
  s21_set.erase(pos);
  EXPECT_EQ(s21_set.contains(8), 0);
}
TEST(SET, ERASE_TEST_4) {
  s21::set<int> s21_set;
  s21_set.insert(9);
  s21_set.insert(-5);
  s21_set.insert(0);
  s21_set.insert(81);
  s21_set.insert(88);
  auto pos = s21_set.end();
  --pos;
  EXPECT_EQ(s21_set.contains(88), 1);
  s21_set.erase(pos);
  EXPECT_EQ(s21_set.contains(88), 0);
}

TEST(SET, CLEAR_TEST_1) {
  s21::set<int> s21_set;
  s21_set.insert(-5);
  s21_set.insert(0);
  s21_set.insert(2);
  s21_set.insert(10);
  s21_set.insert(8);
  EXPECT_EQ(s21_set.empty(), 0);
  s21_set.clear();
  EXPECT_EQ(s21_set.empty(), 1);
}

TEST(SET, CLEAR_TEST_2) {
  s21::set<int> s21_set;
  EXPECT_EQ(s21_set.empty(), 1);
  s21_set.clear();
  EXPECT_EQ(s21_set.empty(), 1);
}

TEST(SET, CLEAR_TEST_3) {
  s21::set<std::string> s21_set;
  EXPECT_EQ(s21_set.empty(), 1);
  s21_set.insert("pair1");
  EXPECT_EQ(s21_set.empty(), 0);
  s21_set.clear();
  EXPECT_EQ(s21_set.empty(), 1);
}

TEST(SET, SIZE_TEST_1) {
  s21::set<std::string> s21_set;
  s21_set.insert("pair1");
  s21_set.insert("pair2");
  s21_set.insert("pair3");
  s21_set.insert("pair4");
  s21_set.insert("pair5");
  EXPECT_EQ(static_cast<int>(s21_set.size()), 5);
  s21_set.erase(s21_set.begin());
  EXPECT_EQ(static_cast<int>(s21_set.size()), 4);
}

TEST(SET, SIZE_TEST_2) {
  s21::set<int> s21_set;
  s21_set.insert(-3);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 1);
  s21_set.insert(5);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 2);
  s21_set.insert(8);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, SIZE_TEST_3) {
  s21::set<int> s21_set;
  EXPECT_EQ(static_cast<int>(s21_set.size()), 0);
}

TEST(SET, SIZE_TEST_4) {
  s21::set<std::string> s21_set;
  s21_set.insert("pair1");
  s21_set.insert("pair2");
  s21_set.insert("pair3");
  s21_set.insert("pair4");
  s21_set.insert("pair5");
  s21_set.insert("pair6");
  s21_set.insert("pair7");
  s21_set.insert("pair8");
  s21_set.insert("pair9");
  s21_set.insert("pair10");
  EXPECT_EQ(static_cast<int>(s21_set.size()), 10);
}

TEST(SET, SIZE_TEST_5) {
  s21::set<std::string> s21_set;
  s21_set.insert("pair1");
  s21_set.insert("pair2");
  s21_set.insert("pair3");
  s21_set.insert("pair4");
  s21_set.insert("pair5");
  auto pos = s21_set.begin();
  s21_set.erase(pos);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 4);
}

TEST(SET, INSERT_MANY_TEST_1) {
  s21::set<std::string> s21_set = {};
  s21_set.insert_many("pair1", "pair2", "pair3");
  EXPECT_EQ(static_cast<int>(s21_set.size()), 3);
}

TEST(SET, INSERT_MANY_TEST_2) {
  s21::set<int> s21_set = {};
  s21_set.insert_many(-7, 8, 6, 9, 11, 15);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 6);
}

TEST(SET, INSERT_MANY_TEST_3) {
  s21::set<double> s21_set = {};
  s21_set.insert_many(12.3, 15.3, 7.78, 8.88, 15.2, 69.7, 123.45, 2598.0,
                      -1235.45, 987.2, -1478.5, 0.005);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 12);
}

TEST(SET, INSERT_MANY_TEST_4) {
  s21::set<int> s21_set = {};
  s21_set.insert_many(-7, 8, 6, 9, 11, 15, -7, 8);
  EXPECT_EQ(static_cast<int>(s21_set.size()), 6);
}