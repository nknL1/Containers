#pragma once

#include <vector>

#include "s21_tree.h"

namespace s21 {
template <typename Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBTree<key_type, key_type>::Iterator;
  using const_iterator = typename RBTree<key_type, key_type>::ConstIterator;
  using size_type = size_t;

  multiset() { root = new RBTree<key_type, key_type>(); }

  multiset(std::initializer_list<value_type> const &items) {
    root = new RBTree<value_type, value_type>();
    for (auto value : items) {
      insert(value);
    }
  }

  multiset(const multiset &m) : multiset() {
    if (!m.empty()) {
      for (auto it = m.begin(); it != m.end(); ++it) {
        this->insert(it.node->key);
      }
    }
  }

  multiset(multiset &&m) { *this = std::move(m); }

  ~multiset() {
    delete this->root;
    root = nullptr;
  }

  multiset operator=(multiset &&ms) {
    if (this != &ms) {
      root = ms.root;
      ms.root = nullptr;
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

  bool empty() const { return root->is_empty(); }

  size_type size() const { return root->size(); }

  size_type max_size() const { return root->max_size(); }

  void clear() { root->clear(); }

  iterator insert(const value_type &value) {
    Node<key_type, value_type> *node = root->find(value);
    if (node) {
      node->next =
          new Node<value_type, value_type>(node->key, node->value, node->color);
      node->next->prev = node;
      root->_size++;
    } else {
      node = root->insert(value, value, false);
    }
    iterator it(node, this->root);
    return it;
  }

  void erase(iterator pos) { root->erase(pos.node); }

  void swap(multiset &other) { root->swap(*(other.root)); }

  void merge(multiset &other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      if (!this->contains(it.node->key)) {
        this->insert(it.node->key);
      }
    }
  }

  size_type count(const Key &key) const {
    size_type count = 0;
    Node<Key, Key> *node = root->find(key);
    if (node) {
      count++;
      while (node->prev != nullptr) {
        node = node->prev;
        count++;
      }
    }
    return count;
  }

  iterator find(const Key &key) const { return lower_bound(key); }

  bool contains(const key_type &key) { return root->contains(key); }

  std::pair<iterator, iterator> equal_range(const Key &key) const {
    iterator start = lower_bound(key);
    iterator end = upper_bound(key);
    return std::pair<iterator, iterator>(start, end);
  }

  iterator lower_bound(const Key &key) const {
    auto it = begin();
    for (; it != end() && it.node->key < key; ++it) {
    }
    return it;
  }

  iterator upper_bound(const Key &key) const {
    auto it = begin();
    for (; it != end() && it.node->key <= key; ++it) {
    }
    return it;
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<Key> arguments{args...};
    std::vector<std::pair<iterator, bool>> result = {};
    for (auto arg : arguments) {
      iterator it = insert(arg);
      std::pair<iterator, bool> element(it, true);
      result.push_back(element);
    }
    return result;
  }

  RBTree<key_type, key_type> *root;
};
}  // namespace s21
