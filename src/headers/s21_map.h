#pragma once

#include <vector>

#include "s21_tree.h"

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename RBTree<key_type, mapped_type>::Iterator;
  using const_iterator = typename RBTree<key_type, mapped_type>::ConstIterator;
  using size_type = size_t;

  map() { root = new RBTree<key_type, mapped_type>(); }

  map(std::initializer_list<value_type> const& items) {
    root = new RBTree<key_type, mapped_type>();
    for (auto value : items) {
      insert(value);
    }
  }

  map(const map& m) : map() {
    for (auto it = m.begin(); it != m.end(); ++it) {
      this->insert(it.node->key, it.node->value);
    }
  }

  map(map&& m) { *this = std::move(m); }

  ~map() { delete root; }

  map operator=(map&& m) {
    if (this != &m) {
      root = m.root;
      m.root = nullptr;
    }
    return *this;
  }

  mapped_type& at(const key_type& key) const { return root->at(key); }

  mapped_type& operator[](const key_type& key) const { return (*root)[key]; }

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

  std::pair<iterator, bool> insert(const value_type& value) {
    Node<key_type, mapped_type>* node = root->find(value.first);
    bool is_inserted = false;
    if (!node) {
      node = root->insert(value.first, value.second, false);
      is_inserted = true;
    }
    iterator it(node, this->root);
    std::pair<iterator, bool> res(it, is_inserted);
    return res;
  }

  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    Node<key_type, mapped_type>* node = root->find(key);
    bool is_inserted = false;
    if (!node) {
      node = root->insert(key, obj, false);
      is_inserted = true;
    }
    iterator it(node, this->root);
    std::pair<iterator, bool> result(it, is_inserted);
    return result;
  }

  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
    Node<key_type, mapped_type>* node = root->find(key);
    bool is_inserted = false;
    if (!node) {
      node = root->insert(key, obj, false);
      is_inserted = true;
    } else {
      node = root->insert(key, obj, true);
    }
    iterator it(node, this->root);
    std::pair<iterator, bool> result(it, is_inserted);
    return result;
  }

  void erase(iterator pos) { root->erase(pos.node); }

  void swap(map& other) { root->swap(*(other.root)); }

  void merge(map& other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      if (!this->contains(it.node->key)) {
        this->insert(it.node->key, it.node->value);
      }
    }
  }

  bool contains(const key_type& key) const { return root->contains(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    std::vector<std::pair<Key, mapped_type>> arguments{args...};
    std::vector<std::pair<iterator, bool>> result = {};
    for (auto arg : arguments) {
      std::pair<iterator, bool> element = insert(arg);
      result.push_back(element);
    }
    return result;
  }

  RBTree<key_type, mapped_type>* root;
};
}  // namespace s21