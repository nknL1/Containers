#include "../headers/s21_map.h"

#include <gtest/gtest.h>

TEST(MAP, CONSTRUCTOR_TEST_1) {
  s21::map<int, int> s21_map_int;
  s21::map<double, double> s21_map_double;
  s21::map<std::string, std::string> s21_map_string;

  EXPECT_EQ(static_cast<int>(s21_map_int.size()), 0);
  EXPECT_EQ(s21_map_int.root->root, nullptr);

  EXPECT_EQ(static_cast<double>(s21_map_double.size()), 0);
  EXPECT_EQ(s21_map_double.root->root, nullptr);

  EXPECT_EQ(static_cast<int>(s21_map_string.size()), 0);
  EXPECT_EQ(s21_map_string.root->root, nullptr);
}

TEST(MAP, CONSTRUCTOR_TEST_2) {
  std::pair<int, double> pair1{1, 2.3};
  std::pair<int, double> pair2{4, 5.6};
  std::pair<int, double> pair3{7, 8.9};
  s21::map<int, double> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);

  EXPECT_EQ(s21_map.root->root->key, 4);
  EXPECT_EQ(s21_map.root->root->left->key, 1);
  EXPECT_EQ(s21_map.root->root->right->key, 7);
}

TEST(MAP, CONSTRUCTOR_TEST_3) {
  std::pair<int, double> pair1{1, 2.3};
  std::pair<int, double> pair2{4, 5.6};
  std::pair<int, double> pair3{7, 8.9};
  std::pair<int, double> pair4{11, 23};
  std::pair<int, double> pair5{41, 56};
  std::pair<int, double> pair6{17, 89};
  s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5, pair6};

  EXPECT_EQ(static_cast<int>(s21_map.size()), 6);

  EXPECT_EQ(s21_map.root->root->key, 4);
  EXPECT_EQ(s21_map.root->root->left->key, 1);
  EXPECT_EQ(s21_map.root->root->right->key, 11);
  EXPECT_EQ(s21_map.root->root->right->left->key, 7);
  EXPECT_EQ(s21_map.root->root->right->right->key, 41);
  EXPECT_EQ(s21_map.root->root->right->right->left->key, 17);
}

TEST(MAP, CONSTRUCTOR_TEST_4) {
  std::pair<int, double> pair1{1, 2.3};
  std::pair<int, double> pair2{4, 5.6};
  std::pair<int, double> pair3{1, 8.9};
  std::pair<int, double> pair4{11, 23};
  std::pair<int, double> pair5{41, 56};
  std::pair<int, double> pair6{11, 89};
  s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5, pair6};

  EXPECT_EQ(static_cast<int>(s21_map.size()), 4);
}

TEST(MAP, CONSTRUCTOR_TEST_5) {
  std::pair<double, std::string> pair1{1.2, "first"};
  std::pair<double, std::string> pair2{3.44, "second"};
  std::pair<double, std::string> pair3{5.666, "third"};
  s21::map<double, std::string> s21_map = {pair1, pair2, pair3};
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, CONSTRUCTOR_TEST_6) {
  std::pair<std::string, int> pair1{"first", 1};
  std::pair<std::string, int> pair2{"second", 2};
  std::pair<std::string, int> pair3{"third", 3};
  s21::map<std::string, int> s21_map = {pair1, pair2, pair3};
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, CONSTRUCTOR_TEST_7) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res(s21_map_ref);
  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(MAP, CONSTRUCTOR_TEST_8) {
  std::pair<double, std::string> pair1{1.4, "first"};
  std::pair<double, std::string> pair2{2.77, "second"};
  std::pair<double, std::string> pair3{3.9, "third"};
  std::pair<double, std::string> pair4{1.4, "four"};
  std::pair<double, std::string> pair5{2.77, "five"};
  std::pair<double, std::string> pair6{3.9, "six"};
  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3,
                                               pair4, pair5, pair6};

  s21::map<double, std::string> s21_map_res(s21_map_ref);
  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(MAP, CONSTRUCTOR_TEST_9) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res = std::move(s21_map_ref);
  EXPECT_EQ(static_cast<int>(s21_map_res.size()), 3);
}

TEST(MAP, CONSTRUCTOR_TEST_10) {
  std::pair<double, std::string> pair1{1.4, "first"};
  std::pair<double, std::string> pair2{2.77, "second"};
  std::pair<double, std::string> pair3{3.9, "third"};
  std::pair<double, std::string> pair4{1.7, "four"};
  std::pair<double, std::string> pair5{2.7, "five"};
  std::pair<double, std::string> pair6{4.9, "six"};
  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3,
                                               pair4, pair5, pair6};
  s21::map<double, std::string> s21_map_res = std::move(s21_map_ref);
  EXPECT_EQ(static_cast<int>(s21_map_res.size()), 6);
}

TEST(MAP, CONSTRUCTOR_TEST_11) {
  s21::map<int, double> s21_map_ref{};
  s21::map<int, double> s21_map_res(s21_map_ref);
  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(MAP, CONSTRUCTOR_TEST_12) {
  std::pair<int, double> pair1{9, 1.4};
  s21::map<int, double> s21_map_ref = {pair1};
  s21::map<int, double> s21_map_res(s21_map_ref);
  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(MAP, INSERT_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first.node->key, 23);
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.first.node->key, 98);
  EXPECT_EQ(insert5.second, 1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_TEST_2) {
  std::pair<double, std::string> pair1{1.4, "first"};
  std::pair<double, std::string> pair2{2.77, "second"};
  std::pair<double, std::string> pair3{3.9, "third"};
  std::pair<double, std::string> pair4{2.77, "second"};
  std::pair<double, std::string> pair5{3.9, "third"};
  s21::map<double, std::string> s21_map;
  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first.node->key, 1.4);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first.node->key, 2.77);
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.first.node->key, 3.9);
  EXPECT_EQ(insert3.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_TEST_3) {
  std::pair<std::string, int> pair1{"first", 1};
  std::pair<std::string, int> pair2{"second", 2};
  std::pair<std::string, int> pair3{"second", 2};
  std::pair<std::string, int> pair4{"third", 3};
  std::pair<std::string, int> pair5{"first", 1};
  s21::map<std::string, int> s21_map;
  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first.node->key, "first");
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first.node->key, "second");
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first.node->key, "third");
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_TEST_4) {
  std::pair<int, double> pair1{9, 1.4};
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair1);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert2.first.node->key, 9);
  EXPECT_EQ(insert3.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
}

TEST(MAP, INSERTKV_TEST_1) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(23, 2.77);
  EXPECT_EQ(insert4.first.node->key, 23);
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(98, 3.9);
  EXPECT_EQ(insert5.first.node->key, 98);
  EXPECT_EQ(insert5.second, 1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTKV_TEST_2) {
  s21::map<double, std::string> s21_map;
  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(1.4, "first");
  EXPECT_EQ(insert1.first.node->key, 1.4);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(2.77, "second");
  EXPECT_EQ(insert2.first.node->key, 2.77);
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(3.9, "third");
  EXPECT_EQ(insert3.first.node->key, 3.9);
  EXPECT_EQ(insert3.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(2.77, "second");
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(3.9, "third");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTKV_TEST_3) {
  s21::map<std::string, int> s21_map;
  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert("first", 1);
  EXPECT_EQ(insert1.first.node->key, "first");
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert("second", 2);
  EXPECT_EQ(insert2.first.node->key, "second");
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert("second", 2);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert("third", 3);
  EXPECT_EQ(insert4.first.node->key, "third");
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert("first", 1);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTKV_4) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert2.first.node->key, 9);
  EXPECT_EQ(insert3.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
}

TEST(MAP, INSERTORASSIGN_TEST_1) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert_or_assign(23, 2.77);
  EXPECT_EQ(insert4.first.node->key, 23);
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert_or_assign(98, 3.9);
  EXPECT_EQ(insert5.first.node->key, 98);
  EXPECT_EQ(insert5.second, 1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_TEST_2) {
  s21::map<double, std::string> s21_map;
  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert_or_assign(1.4, "first");
  EXPECT_EQ(insert1.first.node->key, 1.4);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert_or_assign(2.77, "second");
  EXPECT_EQ(insert2.first.node->key, 2.77);
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert_or_assign(3.9, "third");
  EXPECT_EQ(insert3.first.node->key, 3.9);
  EXPECT_EQ(insert3.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert_or_assign(2.77, "second");
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert_or_assign(3.9, "third");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_TEST_3) {
  s21::map<std::string, int> s21_map;
  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert_or_assign("first", 1);
  EXPECT_EQ(insert1.first.node->key, "first");
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert_or_assign("second", 2);
  EXPECT_EQ(insert2.first.node->key, "second");
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert_or_assign("second", 2);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert_or_assign("third", 3);
  EXPECT_EQ(insert4.first.node->key, "third");
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert_or_assign("first", 1);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_4) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert2.first.node->key, 9);
  EXPECT_EQ(insert3.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
}

TEST(MAP, INSERTORASSIGN_TEST_5) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert_or_assign(23, 2.77);
  EXPECT_EQ(insert4.first.node->key, 23);
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert_or_assign(98, 3.9);
  EXPECT_EQ(insert5.first.node->key, 98);
  EXPECT_EQ(insert5.second, 1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_TEST_6) {
  s21::map<double, std::string> s21_map;
  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert_or_assign(1.4, "first");
  EXPECT_EQ(insert1.first.node->key, 1.4);
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert_or_assign(2.77, "second");
  EXPECT_EQ(insert2.first.node->key, 2.77);
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert_or_assign(3.9, "third");
  EXPECT_EQ(insert3.first.node->key, 3.9);
  EXPECT_EQ(insert3.second, 1);
  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert_or_assign(2.77, "second");
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert_or_assign(3.9, "third");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_TEST_7) {
  s21::map<std::string, int> s21_map;
  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert_or_assign("first", 1);
  EXPECT_EQ(insert1.first.node->key, "first");
  EXPECT_EQ(insert1.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert_or_assign("second", 2);
  EXPECT_EQ(insert2.first.node->key, "second");
  EXPECT_EQ(insert2.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert_or_assign("second", 2);
  EXPECT_EQ(insert3.second, 0);
  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert_or_assign("third", 3);
  EXPECT_EQ(insert4.first.node->key, "third");
  EXPECT_EQ(insert4.second, 1);
  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert_or_assign("first", 1);
  EXPECT_EQ(insert5.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERTORASSIGN_8) {
  s21::map<int, double> s21_map;
  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert_or_assign(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert_or_assign(9, 1.4);
  EXPECT_EQ(insert1.first.node->key, 9);
  EXPECT_EQ(insert2.first.node->key, 9);
  EXPECT_EQ(insert3.first.node->key, 9);
  EXPECT_EQ(insert1.second, 1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
}

TEST(MAP, BEGIN_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{7, 151.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{2, 3.9};
  s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto min_value = s21_map.begin();
  EXPECT_EQ(min_value.node->key, 2);
  EXPECT_EQ(min_value.node->value, 3.9);
}

TEST(MAP, BEGIN_TEST_2) {
  std::pair<double, std::string> pair1{11.4, "first"};
  std::pair<double, std::string> pair2{2.770001, "hee"};
  std::pair<double, std::string> pair3{3.901, "third"};
  std::pair<double, std::string> pair4{2.77, "second"};
  std::pair<double, std::string> pair5{3.9, "hee-hee"};
  s21::map<double, std::string> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto min_value = s21_map.begin();
  EXPECT_EQ((*min_value).first, 2.77);
  EXPECT_EQ((*min_value).second, "second");
}

TEST(MAP, BEGIN_TEST_3) {
  std::pair<std::string, int> pair1{"first", 1};
  std::pair<std::string, int> pair2{"second", 2};
  std::pair<std::string, int> pair3{"second-second", 2};
  std::pair<std::string, int> pair4{"third", 3};
  std::pair<std::string, int> pair5{"first, there", 1};
  s21::map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto min_value = s21_map.begin();
  EXPECT_EQ(min_value.node->key, "first");
  EXPECT_EQ(min_value.node->value, 1);
}

TEST(MAP, BEGIN_TEST_4) {
  s21::map<int, double> s21_map{};
  EXPECT_EQ(s21_map.begin().node, s21_map.root->fake);
}

TEST(MAP, BEGIN_TEST_5) {
  std::pair<double, std::string> pair1{1.4, "first"};
  s21::map<double, std::string> s21_map = {pair1};
  auto min_value = s21_map.begin();
  EXPECT_EQ(min_value.node->key, 1.4);
  EXPECT_EQ(min_value.node->value, "first");
}

TEST(MAP, END_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{7, 151.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{2, 3.9};
  s21::map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto end = s21_map.end();
  --end;
  EXPECT_EQ(end.node->key, 23);
  EXPECT_EQ(end.node->value, 2.77);
}

TEST(MAP, END_TEST_2) {
  std::pair<double, std::string> pair1{11.4, "first"};
  std::pair<double, std::string> pair2{2.770001, "hee"};
  std::pair<double, std::string> pair3{3.901, "third"};
  std::pair<double, std::string> pair4{11.400000001, "second"};
  std::pair<double, std::string> pair5{3.9, "hee-hee"};
  s21::map<double, std::string> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto end = s21_map.end();
  EXPECT_EQ(end.node, s21_map.root->fake);
}

TEST(MAP, END_TEST_3) {
  std::pair<std::string, int> pair1{"first", 1};
  std::pair<std::string, int> pair2{"second", 2};
  std::pair<std::string, int> pair3{"third-third", 2};
  std::pair<std::string, int> pair4{"third", 3};
  std::pair<std::string, int> pair5{"first, there", 1};
  s21::map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};
  auto end = s21_map.end();
  --end;
  EXPECT_EQ(end.node->key, "third-third");
  EXPECT_EQ(end.node->value, 2);
}

TEST(MAP, END_TEST_4) {
  s21::map<int, double> s21_map;
  EXPECT_EQ(s21_map.end().node, s21_map.root->fake);
}

TEST(MAP, END_TEST_5) {
  std::pair<double, std::string> pair1{1.4, "first"};
  s21::map<double, std::string> s21_map = {pair1, pair1};
  auto end = s21_map.end();
  --end;
  EXPECT_EQ(end.node->key, 1.4);
  EXPECT_EQ(end.node->value, "first");
}

TEST(MAP, END_TEST_6) {
  std::pair<std::string, int> pair1{"first", 1};
  s21::map<std::string, int> s21_map = {pair1};
  auto end = s21_map.end();
  --end;
  EXPECT_EQ(end.node->key, "first");
  EXPECT_EQ(end.node->value, 1);
}

TEST(MAP, END_TEST_7) {
  std::pair<std::string, int> pair1{"first", 1};
  s21::map<std::string, int> s21_map = {pair1};
  auto end = s21_map.end();
  EXPECT_THROW(++end, std::out_of_range);
}

TEST(MAP, EMPTY_TEST_1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};
  s21::map<double, int> s21_map = {pair1, pair2, pair3, pair4};
  EXPECT_EQ(s21_map.empty(), 0);
}

TEST(MAP, EMPTY_TEST_2) {
  s21::map<double, int> s21_map;
  EXPECT_EQ(s21_map.empty(), 1);
}

TEST(MAP, SWAP_TEST_1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};
  std::pair<double, int> pair5{22.2, 15};
  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res = {pair3, pair4, pair5};
  s21_map_ref.swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.begin().node->key, 1.44);
  EXPECT_EQ(s21_map_ref.begin().node->value, 3);

  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.begin().node->key, 22.2);
  EXPECT_EQ(s21_map_res.begin().node->value, 1);
}

TEST(MAP, SWAP_TEST_2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 5};
  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res;
  s21_map_ref.swap(s21_map_res);
  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.begin().node->key, 22.2);
  EXPECT_EQ(s21_map_res.begin().node->value, 1);
  auto end = s21_map_res.end();
  --end;
  EXPECT_EQ(end.node->key, 44.48);
  EXPECT_EQ(end.node->value, 5);
}

TEST(MAP, SWAP_TEST_3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};
  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res = {pair1, pair2, pair3};
  s21_map_ref.swap(s21_map_res);
  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.begin().node->key, 1.44);
  EXPECT_EQ(s21_map_ref.begin().node->value, 3);
  auto end = s21_map_ref.end();
  --end;
  EXPECT_EQ(end.node->key, 22.2);
  EXPECT_EQ(end.node->value, 15);
  EXPECT_EQ(s21_map_res.size(), 0U);
}

TEST(MAP, SWAP_TEST_4) {
  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res;
  s21_map_ref.swap(s21_map_res);
  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 0U);
}

TEST(MAP, CONTAINS_TEST_1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  s21::map<double, int> s21_map = {pair1, pair2};
  EXPECT_EQ(s21_map.contains(22.2), true);
  EXPECT_EQ(s21_map.contains(44.48), true);
}

TEST(MAP, CONTAINS_TEST_2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  s21::map<double, int> s21_map_ref = {pair1, pair2};
  s21::map<double, int> s21_map_res;
  s21_map_ref.swap(s21_map_res);
  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_ref.contains(22.2), false);
  EXPECT_EQ(s21_map_ref.contains(44.48), false);
  EXPECT_EQ(s21_map_res.size(), 2U);
  EXPECT_EQ(s21_map_res.contains(22.2), true);
  EXPECT_EQ(s21_map_res.contains(44.48), true);
}

TEST(MAP, CONTAINS_TEST_3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};
  s21::map<double, int> s21_map_ref;
  s21::map<double, int> s21_map_res = {pair1, pair2, pair3};
  s21_map_ref.swap(s21_map_res);
  EXPECT_EQ(s21_map_ref.size(), 3U);
  EXPECT_EQ(s21_map_ref.contains(12.4457), true);
  EXPECT_EQ(s21_map_ref.contains(1.44), true);
  EXPECT_EQ(s21_map_ref.contains(22.2), true);
  EXPECT_EQ(s21_map_res.size(), 0U);
  EXPECT_EQ(s21_map_res.contains(12.4457), false);
  EXPECT_EQ(s21_map_res.contains(1.44), false);
  EXPECT_EQ(s21_map_res.contains(22.2), false);
}

TEST(MAP, CONTAINS_TEST_4) {
  s21::map<double, int> s21_map;
  EXPECT_EQ(s21_map.size(), 0U);
  EXPECT_EQ(s21_map.contains(12.4457), false);
}

TEST(MAP, AT_TEST) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair4{78, 3.9};
  std::pair<int, double> pair5{88, 3.9};
  std::pair<int, double> pair6{108, 3.9};
  s21::map<int, double> s21_map_int{pair1, pair2, pair3, pair4, pair5, pair6};
  EXPECT_EQ(s21_map_int.at(9), 1.4);
  EXPECT_EQ(s21_map_int.at(23), 2.77);
  EXPECT_EQ(s21_map_int.at(98), 3.9);
  EXPECT_EQ(s21_map_int.at(78), 3.9);
  EXPECT_EQ(s21_map_int.at(88), 3.9);
  EXPECT_EQ(s21_map_int.at(108), 3.9);
  EXPECT_THROW(s21_map_int.at(11), std::out_of_range);

  std::pair<double, std::string> pair7{1.4, "first"};
  std::pair<double, std::string> pair8{2.77, "second"};
  std::pair<double, std::string> pair9{3.9, "third"};
  s21::map<double, std::string> s21_map_double{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_double.at(1.4), "first");
  EXPECT_EQ(s21_map_double.at(2.77), "second");
  EXPECT_EQ(s21_map_double.at(3.9), "third");
  EXPECT_THROW(s21_map_double.at(11), std::out_of_range);

  std::pair<std::string, int> pair10{"first", 1};
  std::pair<std::string, int> pair11{"second", 2};
  std::pair<std::string, int> pair12{"third", 3};
  s21::map<std::string, int> s21_map_string{pair10, pair11, pair12};
  EXPECT_EQ(s21_map_string.at("first"), 1);
  EXPECT_EQ(s21_map_string.at("second"), 2);
  EXPECT_EQ(s21_map_string.at("third"), 3);
  EXPECT_THROW(s21_map_string.at("AAAAAA!!!!!"), std::out_of_range);
}

TEST(MAP, BRACKETS_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};
  s21::map<int, double> s21_map_int{pair1,  pair2,  pair3,
                                    pair11, pair22, pair33};
  EXPECT_EQ(s21_map_int[9], 1.4);
  EXPECT_EQ(s21_map_int[23], 2.77);
  EXPECT_EQ(s21_map_int[98], 3.9);
  EXPECT_EQ(s21_map_int[78], 3.9);
  EXPECT_EQ(s21_map_int[88], 3.9);
  EXPECT_EQ(s21_map_int[108], 3.9);
  std::pair<double, std::string> pair4{1.4, "first"};
  std::pair<double, std::string> pair5{2.77, "second"};
  std::pair<double, std::string> pair6{3.9, "third"};
  s21::map<double, std::string> s21_map_double{pair4, pair5, pair6};
  EXPECT_EQ(s21_map_double[1.4], "first");
  EXPECT_EQ(s21_map_double[2.77], "second");
  EXPECT_EQ(s21_map_double[3.9], "third");
  std::pair<std::string, int> pair7{"first", 1};
  std::pair<std::string, int> pair8{"second", 2};
  std::pair<std::string, int> pair9{"third", 3};
  s21::map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string["first"], 1);
  EXPECT_EQ(s21_map_string["second"], 2);
  EXPECT_EQ(s21_map_string["third"], 3);
}

TEST(MAP, BRACKETS_TEST_2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{8, 3.9};
  s21::map<int, double> s21_map_int = {pair1, pair2, pair3};
  s21_map_int[78] = 78.0;
  s21_map_int[88] = 88.0;
  s21_map_int[108] = 108.0;
  EXPECT_EQ(s21_map_int[9], 1.4);
  EXPECT_EQ(s21_map_int[23], 2.77);
  EXPECT_EQ(s21_map_int[8], 3.9);
  EXPECT_EQ(s21_map_int[78], 78.0);
  EXPECT_EQ(s21_map_int[88], 88.0);
  EXPECT_EQ(s21_map_int[108], 108.0);

  std::pair<double, std::string> pair4{1.4, "first"};
  std::pair<double, std::string> pair5{2.77, "second"};
  std::pair<double, std::string> pair6{3.9, "third"};
  s21::map<double, std::string> s21_map_double{pair4, pair5};
  s21_map_double[3.9] = "third";
  EXPECT_EQ(s21_map_double[1.4], "first");
  EXPECT_EQ(s21_map_double[2.77], "second");
  EXPECT_EQ(s21_map_double[3.9], "third");

  std::pair<std::string, int> pair7{"first", 1};
  std::pair<std::string, int> pair8{"second", 2};
  std::pair<std::string, int> pair9{"third", 3};
  s21::map<std::string, int> s21_map_string{pair7};
  s21_map_string["second"] = 2;
  s21_map_string["third"] = 3;
  EXPECT_EQ(s21_map_string["first"], 1);
  EXPECT_EQ(s21_map_string["second"], 2);
  EXPECT_EQ(s21_map_string["third"], 3);
}

TEST(MAP, MERGE_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 4.59};
  std::pair<int, double> pair22{88, 12.902};
  std::pair<int, double> pair33{108, 56.41};
  s21::map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  s21::map<int, double> s21_map_int_res{pair11, pair22, pair33};
  s21_map_int_res.merge(s21_map_int_ref);
  EXPECT_EQ(static_cast<int>(s21_map_int_res.size()), 6);
}

TEST(MAP, MERGE_TEST_2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  s21::map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  s21::map<int, double> s21_map_int_res;
  s21_map_int_res.merge(s21_map_int_ref);
  EXPECT_EQ(static_cast<int>(s21_map_int_res.size()), 3);
}

TEST(MAP, MERGE_TEST_3) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  s21::map<int, double> s21_map_int_ref;
  s21::map<int, double> s21_map_int_res{pair1, pair2, pair3};
  EXPECT_EQ(static_cast<int>(s21_map_int_res.size()), 3);
}

TEST(MAP, MERGE_TEST_4) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair4{1, 22.2};
  std::pair<int, double> pair5{8, 44.48};
  std::pair<int, double> pair6{32, 12.4457};
  s21::map<int, double> s21_map_int_ref = {pair1, pair2, pair3, pair4};
  s21::map<int, double> s21_map_int_res = {pair5, pair6};
  s21_map_int_res.merge(s21_map_int_ref);
  EXPECT_EQ(static_cast<int>(s21_map_int_res.size()), 6);
}

TEST(MAP, MERGE_TEST_5) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair4{1, 22.2};
  std::pair<int, double> pair5{9, 44.48};
  std::pair<int, double> pair6{98, 12.4457};
  s21::map<int, double> s21_map_int_ref = {pair1, pair2, pair3, pair4};
  s21::map<int, double> s21_map_int_res = {pair5, pair6};
  s21_map_int_res.merge(s21_map_int_ref);
  EXPECT_EQ(static_cast<int>(s21_map_int_res.size()), 4);
}

TEST(MAP, ERASE_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  auto pos = s21_map.begin();
  EXPECT_EQ(s21_map.contains(9), 1);
  s21_map.erase(pos);
  EXPECT_EQ(s21_map.contains(9), 0);
}

TEST(MAP, ERASE_TEST_2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{4, 5.5};
  std::pair<int, double> pair3{8, 11.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  auto pos = s21_map.begin();
  ++pos;
  EXPECT_EQ(s21_map.contains(8), 1);
  s21_map.erase(pos);
  EXPECT_EQ(s21_map.contains(8), 0);
}

TEST(MAP, ERASE_TEST_3) {
  std::pair<int, double> pair1{11, 123.4};
  std::pair<int, double> pair2{3, 1.23};
  std::pair<int, double> pair3{45, 1.7};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  auto pos = s21_map.begin();
  ++pos;
  ++pos;
  EXPECT_EQ(s21_map.contains(23), 1);
  s21_map.erase(pos);
  EXPECT_EQ(s21_map.contains(23), 0);
}

TEST(MAP, ERASE_TEST_4) {
  std::pair<int, double> pair1{11, 1.4};
  std::pair<int, double> pair2{34, 1.4};
  std::pair<int, double> pair3{22, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  auto pos = s21_map.end();
  --pos;
  EXPECT_EQ(s21_map.contains(98), 1);
  s21_map.erase(pos);
  EXPECT_EQ(s21_map.contains(98), 0);
}

TEST(MAP, CLEAR_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  EXPECT_EQ(s21_map.empty(), 0);
  s21_map.clear();
  EXPECT_EQ(s21_map.empty(), 1);
}

TEST(MAP, CLEAR_TEST_2) {
  s21::map<int, double> s21_map;
  EXPECT_EQ(s21_map.empty(), 1);
  s21_map.clear();
  EXPECT_EQ(s21_map.empty(), 1);
}

TEST(MAP, CLEAR_TEST_3) {
  s21::map<int, double> s21_map;
  EXPECT_EQ(s21_map.empty(), 1);
  std::pair<int, double> pair1{9, 1.4};
  s21_map.insert(pair1);
  EXPECT_EQ(s21_map.empty(), 0);
  s21_map.clear();
  EXPECT_EQ(s21_map.empty(), 1);
}

TEST(MAP, SIZE_TEST_1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{91, 1.4};
  std::pair<int, double> pair3{19, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 5);
  s21_map.erase(s21_map.begin());
  EXPECT_EQ(static_cast<int>(s21_map.size()), 4);
}

TEST(MAP, SIZE_TEST_2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{4, 5.5};
  std::pair<int, double> pair3{8, 11.4};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
  s21_map.insert(pair2);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 2);
  s21_map.insert(pair3);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, SIZE_TEST_3) {
  s21::map<int, double> s21_map;
  EXPECT_EQ(static_cast<int>(s21_map.size()), 0);
}

TEST(MAP, SIZE_TEST_4) {
  std::pair<int, double> pair1{11, 1.4};
  std::pair<int, double> pair2{34, 1.4};
  std::pair<int, double> pair3{22, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  std::pair<int, double> pair6{21, 1.4};
  std::pair<int, double> pair7{67, 1.4};
  std::pair<int, double> pair8{49, 1.4};
  std::pair<int, double> pair9{17, 2.77};
  std::pair<int, double> pair10{93, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  s21_map.insert(pair6);
  s21_map.insert(pair7);
  s21_map.insert(pair8);
  s21_map.insert(pair9);
  s21_map.insert(pair10);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 10);
}

TEST(MAP, SIZE_TEST_5) {
  std::pair<int, double> pair1{11, 1.4};
  std::pair<int, double> pair2{34, 1.4};
  std::pair<int, double> pair3{22, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};
  s21::map<int, double> s21_map;
  s21_map.insert(pair1);
  s21_map.insert(pair2);
  s21_map.insert(pair3);
  s21_map.insert(pair4);
  s21_map.insert(pair5);
  auto pos = s21_map.begin();
  s21_map.erase(pos);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 4);
}

TEST(MAP, INSERT_MANY_TEST_1) {
  s21::map<std::string, int> s21_map = {};
  std::pair<std::string, int> pair1{"first", 1};
  std::pair<std::string, int> pair2{"second", 2};
  std::pair<std::string, int> pair3{"third", 3};
  s21_map.insert_many(pair1, pair2, pair3);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_MANY_TEST_2) {
  s21::map<int, int> s21_map = {};
  std::pair<int, int> pair1{12, 1};
  std::pair<int, int> pair2{-5, 2};
  std::pair<int, int> pair3{8, 3};
  s21_map.insert_many(pair1, pair2, pair3);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_MANY_TEST_3) {
  s21::map<int, int> s21_map = {};
  std::pair<int, int> pair1{12, 1};
  std::pair<int, int> pair2{-5, 2};
  std::pair<int, int> pair3{8, 3};
  std::pair<int, int> pair4{12, 1};
  std::pair<int, int> pair5{-5, 2};
  std::pair<int, int> pair6{8, 3};
  s21_map.insert_many(pair1, pair2, pair3, pair4, pair5, pair6);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 3);
}

TEST(MAP, INSERT_MANY_TEST_4) {
  s21::map<std::string, int> s21_map = {};
  std::pair<std::string, int> pair1{"first", 1};
  s21_map.insert_many(pair1);
  EXPECT_EQ(static_cast<int>(s21_map.size()), 1);
}
