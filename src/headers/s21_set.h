#pragma once

#include <vector>

#include "s21_tree.h"

namespace s21 {
template <typename Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBTree<key_type, key_type>::Iterator;
  using const_iterator = typename RBTree<key_type, key_type>::ConstIterator;
  using size_type = size_t;

  set() { root = new RBTree<key_type, key_type>(); }

  set(std::initializer_list<value_type> const &items) {
    root = new RBTree<key_type, key_type>();
    for (auto value : items) {
      insert(value);
    }
  }

  set(const set &m) : set() {
    for (auto it = m.begin(); it != m.end(); ++it) {
      this->insert(it.node->key);
    }
  }

  set(set &&m) noexcept : root(m.root) { m.root = nullptr; }

  ~set() {
    delete root;
    root = nullptr;
  }

  set operator=(set &&s) {
    if (this != &s) {
      root = s.root;
      s.root = nullptr;
    }
    return *this;
  }

  iterator begin() const {
    iterator result(root->begin(), this->root);
    return result;
  }

  iterator end() const {
    iterator result(root->end(), this->root);
    return result;
  }

  bool empty() { return root->is_empty(); }

  size_type size() { return root->size(); }

  size_type max_size() { return root->max_size(); }

  void clear() { root->clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    Node<Key, Key> *node = root->find(value);
    bool is_inserted = false;
    if (!node) {
      node = root->insert(value, value, false);
      is_inserted = true;
    }
    iterator it(node, this->root);
    std::pair<iterator, bool> result(it, is_inserted);
    return result;
  }

  void erase(iterator pos) {
    if (pos != end()) {
      root->erase(pos.node);
      pos.node = nullptr;
    }
  }

  void swap(set &other) { root->swap(*(other.root)); }

  void merge(set &other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      if (!this->contains(it.node->key)) {
        this->insert(it.node->key);
      }
    }
  }

  iterator find(const Key &key) {
    return new iterator(root->find(key), this->root);
  }

  bool contains(const key_type &key) { return root->contains(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<Key> arguments{args...};
    std::vector<std::pair<iterator, bool>> result = {};
    for (auto arg : arguments) {
      std::pair<iterator, bool> element = insert(arg);
      result.push_back(element);
    }
    return result;
  }

  RBTree<key_type, key_type> *root;
};
}  // namespace s21