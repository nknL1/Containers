#include "../headers/s21_multiset.h"

#include <gtest/gtest.h>

TEST(MULTISET, CONSTRUCTOR_TEST_1) {
  s21::multiset<int> s21_multiset_int;
  s21::multiset<double> s21_multiset_double;
  s21::multiset<std::string> s21_multiset_string;

  EXPECT_EQ(static_cast<int>(s21_multiset_int.size()), 0);
  EXPECT_EQ(s21_multiset_int.root->root, nullptr);

  EXPECT_EQ(static_cast<double>(s21_multiset_double.size()), 0);
  EXPECT_EQ(s21_multiset_double.root->root, nullptr);

  EXPECT_EQ(static_cast<int>(s21_multiset_string.size()), 0);
  EXPECT_EQ(s21_multiset_string.root->root, nullptr);
}

TEST(MULTISET, CONSTRUCTOR_TEST_2) {
  s21::multiset<double> s21_multiset = {2.3, 55.5, 88.};

  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 3);

  EXPECT_EQ(s21_multiset.root->root->key, 55.5);
  EXPECT_EQ(s21_multiset.root->root->left->key, 2.3);
  EXPECT_EQ(s21_multiset.root->root->right->key, 88.);
}

TEST(MULTISET, CONSTRUCTOR_TEST_3) {
  s21::multiset<int> s21_multiset = {1, 4, 7, 11, 41, 17};

  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 6);

  EXPECT_EQ(s21_multiset.root->root->key, 4);
  EXPECT_EQ(s21_multiset.root->root->left->key, 1);
  EXPECT_EQ(s21_multiset.root->root->right->key, 11);
  EXPECT_EQ(s21_multiset.root->root->right->left->key, 7);
  EXPECT_EQ(s21_multiset.root->root->right->right->key, 41);
  EXPECT_EQ(s21_multiset.root->root->right->right->left->key, 17);
}

TEST(MULTISET, CONSTRUCTOR_TEST_4) {
  s21::multiset<int> s21_multiset = {1, 4, 7, 11, 41, 17, 1, 4};

  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 8);

  EXPECT_EQ(s21_multiset.root->root->key, 4);
  EXPECT_EQ(s21_multiset.root->root->left->key, 1);
  EXPECT_EQ(s21_multiset.root->root->right->key, 11);
  EXPECT_EQ(s21_multiset.root->root->right->left->key, 7);
  EXPECT_EQ(s21_multiset.root->root->right->right->key, 41);
  EXPECT_EQ(s21_multiset.root->root->right->right->left->key, 17);
}

TEST(MULTISET, CONSTRUCTOR_TEST_5) {
  s21::multiset<std::string> s21_multiset = {"first", "second", "third"};
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 3);
}

TEST(MULTISET, CONSTRUCTOR_TEST_6) {
  s21::multiset<std::string> s21_multiset = {"first", "second", "third",
                                             "first", "second", "third"};
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 6);
}

TEST(MULTISET, CONSTRUCTOR_TEST_7) {
  s21::multiset<int> s21_multiset_ref = {1, 4, 7, 11, 41, 17};
  s21::multiset<int> s21_multiset_res(s21_multiset_ref);
  EXPECT_EQ(s21_multiset_res.size(), s21_multiset_ref.size());
}

TEST(MULTISET, CONSTRUCTOR_TEST_8) {
  s21::multiset<std::string> s21_multiset_ref = {"first", "second", "third",
                                                 "four",  "five",   "six"};

  s21::multiset<std::string> s21_multiset_res(s21_multiset_ref);
  EXPECT_EQ(s21_multiset_res.size(), s21_multiset_ref.size());
}

TEST(MULTISET, CONSTRUCTOR_TEST_9) {
  s21::multiset<double> s21_multiset_ref = {1.4, 2.77, 3.9};
  s21::multiset<double> s21_multiset_res(s21_multiset_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 3);
}

TEST(MULTISET, CONSTRUCTOR_TEST_10) {
  s21::multiset<std::string> s21_multiset_ref = {"first", "second", "third",
                                                 "four",  "five",   "six"};
  s21::multiset<std::string> s21_multiset_res(s21_multiset_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 6);
}

TEST(MULTISET, CONSTRUCTOR_TEST_11) {
  s21::multiset<std::string> s21_multiset_ref = {};
  s21::multiset<std::string> s21_multiset_res(s21_multiset_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 0);
}

TEST(MULTISET, CONSTRUCTOR_TEST_14) {
  s21::multiset<double> s21_multiset_ref = {1.4, 2.77, 3.9};
  s21::multiset<double> s21_multiset_res = std::move(s21_multiset_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 3);
}

TEST(MULTISET, INSERT_TEST_1) {
  s21::multiset<int> s21_multiset;
  auto insert1 = s21_multiset.insert(9);
  EXPECT_EQ(insert1.node->key, 9);
  auto insert4 = s21_multiset.insert(23);
  EXPECT_EQ(insert4.node->key, 23);
  auto insert5 = s21_multiset.insert(98);
  EXPECT_EQ(insert5.node->key, 98);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 3);
}

TEST(MULTISET, INSERT_TEST_2) {
  s21::multiset<std::string> s21_multiset;
  auto insert1 = s21_multiset.insert("first");
  EXPECT_EQ(insert1.node->key, "first");
  auto insert2 = s21_multiset.insert("second");
  EXPECT_EQ(insert2.node->key, "second");
  auto insert3 = s21_multiset.insert("third");
  EXPECT_EQ(insert3.node->key, "third");
  auto insert4 = s21_multiset.insert("first");
  EXPECT_EQ(insert4.node->key, "first");
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 4);
}

TEST(MULTISET, INSERT_TEST_3) {
  s21::multiset<double> s21_multiset;
  auto insert1 = s21_multiset.insert(9.8);
  EXPECT_EQ(insert1.node->key, 9.8);
  auto insert2 = s21_multiset.insert(3.14);
  EXPECT_EQ(insert2.node->key, 3.14);
  auto insert3 = s21_multiset.insert(78.8);
  EXPECT_EQ(insert3.node->key, 78.8);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 3);
}

TEST(MULTISET, INSERT_4) {
  s21::multiset<int> s21_multiset;
  auto insert1 = s21_multiset.insert(9);
  EXPECT_EQ(insert1.node->key, 9);
}

TEST(MULTISET, BEGIN_TEST_1) {
  s21::multiset<double> s21_multiset = {9.8, 42.8, 3.14, 1.11, 2.12};
  auto min_value = s21_multiset.begin();
  EXPECT_EQ(min_value.node->key, 1.11);
}

TEST(MULTISET, BEGIN_TEST_2) {
  s21::multiset<std::string> s21_multiset = {"first", "hee", "second", "third",
                                             "hee-hee"};
  auto min_value = s21_multiset.begin();
  EXPECT_EQ(min_value.node->key, "first");
}

TEST(MULTISET, BEGIN_TEST_3) {
  s21::multiset<int> s21_multiset = {5, 8, 15, -3, 0};
  auto min_value = s21_multiset.begin();
  EXPECT_EQ(min_value.node->key, -3);
}

TEST(MULTISET, BEGIN_TEST_4) {
  s21::multiset<int> s21_multiset{};
  EXPECT_EQ(s21_multiset.begin().node, s21_multiset.root->fake);
}

TEST(MULTISET, BEGIN_TEST_5) {
  s21::multiset<double> s21_multiset = {8.88};
  auto min_value = s21_multiset.begin();
  EXPECT_EQ(min_value.node->key, 8.88);
}

TEST(MULTISET, END_TEST_1) {
  s21::multiset<double> s21_multiset = {-5.56, 84.1, 0, 88.88, 77.7};
  auto end = s21_multiset.end();
  --end;
  EXPECT_EQ(end.node->key, 88.88);
}

TEST(MULTISET, END_TEST_2) {
  s21::multiset<std::string> s21_multiset = {"first", "hee", "third", "second",
                                             "hee-hee"};
  auto end = s21_multiset.end();
  --end;
  EXPECT_EQ(end.node->key, "third");
}

TEST(MULTISET, END_TEST_3) {
  s21::multiset<int> s21_multiset = {5, 10, -4, -8, 88};
  auto end = s21_multiset.end();
  --end;
  EXPECT_EQ(end.node->key, 88);
}

TEST(MULTISET, END_TEST_4) {
  s21::multiset<double> s21_multiset;
  EXPECT_EQ(s21_multiset.end().node, s21_multiset.root->fake);
}

TEST(MULTISET, END_TEST_5) {
  s21::multiset<std::string> s21_multiset = {"first"};
  auto end = s21_multiset.end();
  --end;
  EXPECT_EQ(end.node->value, "first");
}

TEST(MULTISET, END_TEST_6) {
  s21::multiset<int> s21_multiset = {8};
  auto end = s21_multiset.end();
  --end;
  EXPECT_EQ(end.node->key, 8);
}

TEST(MULTISET, EMPTY_TEST_1) {
  s21::multiset<double> s21_multiset = {3.14, -5.15, 8, 99};
  EXPECT_EQ(s21_multiset.empty(), 0);
}

TEST(MULTISET, EMPTY_TEST_2) {
  s21::multiset<int> s21_multiset;
  EXPECT_EQ(s21_multiset.empty(), 1);
}

TEST(MULTISET, SWAP_TEST_1) {
  s21::multiset<double> s21_multiset_ref = {3.8, -5};
  s21::multiset<double> s21_multiset_res = {4.2, 8.8, 15};
  s21_multiset_ref.swap(s21_multiset_res);

  EXPECT_EQ(s21_multiset_ref.size(), 3U);
  EXPECT_EQ(s21_multiset_ref.begin().node->key, 4.2);

  EXPECT_EQ(s21_multiset_res.size(), 2U);
  EXPECT_EQ(s21_multiset_res.begin().node->key, -5);
}

TEST(MULTISET, SWAP_TEST_2) {
  s21::multiset<int> s21_multiset_ref = {3, 8};
  s21::multiset<int> s21_multiset_res;
  s21_multiset_ref.swap(s21_multiset_res);
  EXPECT_EQ(s21_multiset_ref.size(), 0U);
  EXPECT_EQ(s21_multiset_res.size(), 2U);
  EXPECT_EQ(s21_multiset_res.begin().node->key, 3);
  auto end = s21_multiset_res.end();
  --end;
  EXPECT_EQ(end.node->key, 8);
}

TEST(MULTISET, SWAP_TEST_3) {
  s21::multiset<int> s21_multiset_ref;
  s21::multiset<int> s21_multiset_res = {3, -5, 8};
  s21_multiset_ref.swap(s21_multiset_res);
  EXPECT_EQ(s21_multiset_ref.size(), 3U);
  EXPECT_EQ(s21_multiset_ref.begin().node->key, -5);
  auto end = s21_multiset_ref.end();
  --end;
  EXPECT_EQ(end.node->key, 8);
  EXPECT_EQ(s21_multiset_res.size(), 0U);
}

TEST(MULTISET, SWAP_TEST_4) {
  s21::multiset<double> s21_multiset_ref;
  s21::multiset<double> s21_multiset_res;
  s21_multiset_ref.swap(s21_multiset_res);
  EXPECT_EQ(s21_multiset_ref.size(), 0U);
  EXPECT_EQ(s21_multiset_res.size(), 0U);
}

TEST(MULTISET, CONTAINS_TEST_1) {
  s21::multiset<double> s21_multiset = {3.14, 88.8};
  EXPECT_EQ(s21_multiset.contains(3.14), true);
  EXPECT_EQ(s21_multiset.contains(88.8), true);
  EXPECT_EQ(s21_multiset.contains(888.7), false);
}

TEST(MULTISET, CONTAINS_TEST_2) {
  s21::multiset<int> s21_multiset_ref = {3, 8};
  s21::multiset<int> s21_multiset_res;
  s21_multiset_ref.swap(s21_multiset_res);
  EXPECT_EQ(s21_multiset_ref.size(), 0U);
  EXPECT_EQ(s21_multiset_res.size(), 2U);
  EXPECT_EQ(s21_multiset_ref.contains(3), false);
  EXPECT_EQ(s21_multiset_ref.contains(8), false);

  EXPECT_EQ(s21_multiset_res.contains(3), true);
  EXPECT_EQ(s21_multiset_res.contains(8), true);
}

TEST(MULTISET, CONTAINS_TEST_3) {
  s21::multiset<std::string> s21_multiset_ref;
  s21::multiset<std::string> s21_multiset_res = {"pair1", "pair2", "pair3"};
  EXPECT_EQ(static_cast<int>(s21_multiset_ref.size()), 0);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 3);
  s21_multiset_ref.swap(s21_multiset_res);
  EXPECT_EQ(static_cast<int>(s21_multiset_ref.size()), 3);
  EXPECT_EQ(s21_multiset_ref.contains("pair1"), true);
  EXPECT_EQ(s21_multiset_ref.contains("pair2"), true);
  EXPECT_EQ(s21_multiset_ref.contains("pair3"), true);
  EXPECT_EQ(static_cast<int>(s21_multiset_res.size()), 0);
  EXPECT_EQ(s21_multiset_res.contains("pair1"), false);
  EXPECT_EQ(s21_multiset_res.contains("pair2"), false);
  EXPECT_EQ(s21_multiset_res.contains("pair3"), false);
}

TEST(MULTISET, CONTAINS_TEST_4) {
  s21::multiset<double> s21_multiset;
  EXPECT_EQ(s21_multiset.size(), 0U);
  EXPECT_EQ(s21_multiset.contains(12.4457), false);
}

TEST(MULTISET, MERGE_TEST_1) {
  s21::multiset<int> s21_multiset_int_ref{3, -5, 8};
  s21::multiset<int> s21_multiset_int_res{7, 0, -9};
  s21_multiset_int_res.merge(s21_multiset_int_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_int_res.size()), 6);
}

TEST(MULTISET, MERGE_TEST_2) {
  s21::multiset<int> s21_multiset_int_ref{8, -3, 0};
  s21::multiset<int> s21_multiset_int_res;
  s21_multiset_int_res.merge(s21_multiset_int_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_int_res.size()), 3);
}

TEST(MULTISET, MERGE_TEST_3) {
  s21::multiset<double> s21_multiset_int_ref;
  s21::multiset<double> s21_multiset_int_res{3.14, 0, 8.88};
  EXPECT_EQ(static_cast<int>(s21_multiset_int_res.size()), 3);
}

TEST(MULTISET, MERGE_TEST_4) {
  s21::multiset<std::string> s21_multiset_int_ref = {"pair1", "pair2", "pair3",
                                                     "pair4"};
  s21::multiset<std::string> s21_multiset_int_res = {"pair5", "pair6"};
  s21_multiset_int_res.merge(s21_multiset_int_ref);
  EXPECT_EQ(static_cast<int>(s21_multiset_int_res.size()), 6);
}

TEST(MULTISET, ERASE_TEST_1) {
  s21::multiset<std::string> s21_multiset;
  s21_multiset.insert("pair1");
  s21_multiset.insert("pair2");
  s21_multiset.insert("pair3");
  s21_multiset.insert("pair4");
  s21_multiset.insert("pair5");
  auto pos = s21_multiset.begin();
  EXPECT_EQ(s21_multiset.contains("pair1"), 1);
  s21_multiset.erase(pos);
  EXPECT_EQ(s21_multiset.contains("pair1"), 0);
}

TEST(MULTISET, ERASE_TEST_2) {
  s21::multiset<double> s21_multiset;
  s21_multiset.insert(3.14);
  s21_multiset.insert(0);
  s21_multiset.insert(-5);
  s21_multiset.insert(88.8);
  s21_multiset.insert(7.1);
  auto pos = s21_multiset.begin();
  ++pos;
  EXPECT_EQ(s21_multiset.contains(0), 1);
  s21_multiset.erase(pos);
  EXPECT_EQ(s21_multiset.contains(0), 0);
}

TEST(MULTISET, ERASE_TEST_3) {
  s21::multiset<int> s21_multiset;
  s21_multiset.insert(-5);
  s21_multiset.insert(0);
  s21_multiset.insert(8);
  s21_multiset.insert(11);
  s21_multiset.insert(14);
  auto pos = s21_multiset.begin();
  ++pos;
  ++pos;
  EXPECT_EQ(s21_multiset.contains(8), 1);
  s21_multiset.erase(pos);
  EXPECT_EQ(s21_multiset.contains(8), 0);
}
TEST(MULTISET, ERASE_TEST_4) {
  s21::multiset<int> s21_multiset;
  s21_multiset.insert(9);
  s21_multiset.insert(-5);
  s21_multiset.insert(0);
  s21_multiset.insert(81);
  s21_multiset.insert(88);
  auto pos = s21_multiset.end();
  --pos;
  EXPECT_EQ(s21_multiset.contains(88), 1);
  s21_multiset.erase(pos);
  EXPECT_EQ(s21_multiset.contains(88), 0);
}

TEST(MULTISET, CLEAR_TEST_1) {
  s21::multiset<int> s21_multiset;
  s21_multiset.insert(-5);
  s21_multiset.insert(0);
  s21_multiset.insert(2);
  s21_multiset.insert(10);
  s21_multiset.insert(8);
  EXPECT_EQ(s21_multiset.empty(), 0);
  s21_multiset.clear();
  EXPECT_EQ(s21_multiset.empty(), 1);
}

TEST(MULTISET, CLEAR_TEST_2) {
  s21::multiset<int> s21_multiset;
  EXPECT_EQ(s21_multiset.empty(), 1);
  s21_multiset.clear();
  EXPECT_EQ(s21_multiset.empty(), 1);
}

TEST(MULTISET, CLEAR_TEST_3) {
  s21::multiset<std::string> s21_multiset;
  EXPECT_EQ(s21_multiset.empty(), 1);
  s21_multiset.insert("pair1");
  EXPECT_EQ(s21_multiset.empty(), 0);
  s21_multiset.clear();
  EXPECT_EQ(s21_multiset.empty(), 1);
}

TEST(MULTISET, SIZE_TEST_1) {
  s21::multiset<std::string> s21_multiset;
  s21_multiset.insert("pair1");
  s21_multiset.insert("pair2");
  s21_multiset.insert("pair3");
  s21_multiset.insert("pair4");
  s21_multiset.insert("pair5");
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 5);
  s21_multiset.erase(s21_multiset.begin());
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 4);
}

TEST(MULTISET, SIZE_TEST_2) {
  s21::multiset<int> s21_multiset;
  s21_multiset.insert(-3);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 1);
  s21_multiset.insert(5);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 2);
  s21_multiset.insert(8);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 3);
}

TEST(MULTISET, SIZE_TEST_3) {
  s21::multiset<int> s21_multiset;
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 0);
}

TEST(MULTISET, SIZE_TEST_4) {
  s21::multiset<std::string> s21_multiset;
  s21_multiset.insert("pair1");
  s21_multiset.insert("pair2");
  s21_multiset.insert("pair3");
  s21_multiset.insert("pair4");
  s21_multiset.insert("pair5");
  s21_multiset.insert("pair6");
  s21_multiset.insert("pair7");
  s21_multiset.insert("pair8");
  s21_multiset.insert("pair9");
  s21_multiset.insert("pair10");
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 10);
}

TEST(MULTISET, SIZE_TEST_5) {
  s21::multiset<std::string> s21_multiset;
  s21_multiset.insert("pair1");
  s21_multiset.insert("pair2");
  s21_multiset.insert("pair3");
  s21_multiset.insert("pair4");
  s21_multiset.insert("pair5");
  auto pos = s21_multiset.begin();
  s21_multiset.erase(pos);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 4);
}

TEST(MULTISET, COUNT_TEST_1) {
  s21::multiset<int> s21_multiset = {5, 2, 4, 3,  12, 7,  5,  5,  5,
                                     3, 6, 5, 12, 12, 12, 12, 18, 20};
  EXPECT_EQ(static_cast<int>(s21_multiset.count(21)), 0);
  EXPECT_EQ(static_cast<int>(s21_multiset.count(5)), 5);
  EXPECT_EQ(static_cast<int>(s21_multiset.count(12)), 5);
  EXPECT_EQ(static_cast<int>(s21_multiset.count(3)), 2);
  EXPECT_EQ(static_cast<int>(s21_multiset.count(18)), 1);
}

TEST(MULTISET, COUNT_TEST_2) {
  s21::multiset<int> s21_multiset = {};
  EXPECT_EQ(static_cast<int>(s21_multiset.count(21)), 0);
}

TEST(MULTISET, INSERT_MANY_TEST_1) {
  s21::multiset<std::string> s21_multiset = {};
  s21_multiset.insert_many("pair1", "pair2", "pair3", "pair4", "pair5");
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 5);
}

TEST(MULTISET, INSERT_MANY_TEST_2) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(static_cast<int>(s21_multiset.size()), 12);
}

TEST(MULTISET, UPPER_BOUND_TEST_1) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(s21_multiset.upper_bound(5).node->key, 6);
}

TEST(MULTISET, UPPER_BOUND_TEST_2) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(s21_multiset.upper_bound(-5).node->key, 0);
}

TEST(MULTISET, UPPER_BOUND_TEST_3) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(s21_multiset.upper_bound(3).node->key, 4);
}

TEST(MULTISET, UPPER_BOUND_TEST_4) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(s21_multiset.upper_bound(8), s21_multiset.end());
}

TEST(MULTISET, LOWER_BOUND_TEST_1) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(-5, 0, 2, 5, 7, 0, 1, 5, 4, 6, 7, 8);
  EXPECT_EQ(s21_multiset.lower_bound(12), s21_multiset.end());
}

TEST(MULTISET, LOWER_BOUND_TEST_2) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);
  EXPECT_EQ(s21_multiset.lower_bound(20).node->key, 20);
}

TEST(MULTISET, LOWER_BOUND_TEST_3) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);
  EXPECT_EQ(s21_multiset.lower_bound(8).node->key, 12);
}

TEST(MULTISET, EQUAL_RANGE_TEST_1) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);

  EXPECT_EQ(s21_multiset.equal_range(7).first.node->key, 7);
  EXPECT_EQ(s21_multiset.equal_range(7).second.node->key, 12);
}

TEST(MULTISET, EQUAL_RANGE_TEST_2) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);

  EXPECT_EQ(s21_multiset.equal_range(14).first.node->key, 18);
  EXPECT_EQ(s21_multiset.equal_range(14).second.node->key, 18);
}

TEST(MULTISET, EQUAL_RANGE_TEST_3) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);

  EXPECT_EQ(s21_multiset.equal_range(20).first.node->key, 20);
  EXPECT_EQ(s21_multiset.equal_range(20).second, s21_multiset.end());
}

TEST(MULTISET, EQUAL_RANGE_TEST_4) {
  s21::multiset<int> s21_multiset = {};
  s21_multiset.insert_many(5, 2, 4, 3, 12, 7, 5, 5, 5, 3, 6, 5, 12, 12, 12, 12,
                           18, 20, 20, 20);

  EXPECT_EQ(s21_multiset.equal_range(5).first.node->key, 5);
  EXPECT_EQ(s21_multiset.equal_range(5).second.node->key, 6);
}
