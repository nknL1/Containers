#pragma once

#include <initializer_list>
#include <iostream>

#include "s21_queue.h"

namespace s21 {

enum Color { RED, BLACK };

template <typename Key, typename Value>
struct Node {
  Key key;
  Value value;
  Color color;
  Node *parent;
  Node *left;
  Node *right;
  Node *next;
  Node *prev;

  Node(Key key, Value value, Color color)
      : key(key),
        value(value),
        color(color),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        next(nullptr),
        prev(nullptr) {}

  Node() = default;

  ~Node() {
    if (next != nullptr) delete next;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }

  bool operator==(const Node<Key, Value> other) {
    return this->key == other.key && this->value == other.value;
  }

  bool operator!=(const Node<Key, Value> other) { return !(*this == other); }
};

template <typename Key, typename Value>
class RBTree {
 public:
  RBTree();
  RBTree(std::initializer_list<std::pair<const Key, Value>> const &items);
  RBTree(const RBTree &tree);
  RBTree(RBTree &&tree);
  ~RBTree();
  RBTree<Key, Value> &operator=(const RBTree &&t);
  RBTree<Key, Value> &operator=(const RBTree &t);

  bool contains(const Key &key);
  bool is_empty();
  size_t size();
  size_t max_size();
  void clear();
  void swap(RBTree<Key, Value> &other);

  Value &at(const Key &key);
  Value &operator[](const Key &key);

  void rotate_right(Node<Key, Value> *node);
  void rotate_left(Node<Key, Value> *node);
  void balance(Node<Key, Value> *current);

  void transplant(Node<Key, Value> *node, Node<Key, Value> *child);
  void delete_node(Node<Key, Value> *node);
  void fix_delete(Node<Key, Value> *node);
  Node<Key, Value> *find(const Key &key);
  Node<Key, Value> *find_max(Node<Key, Value> *node);
  Node<Key, Value> *find_min(Node<Key, Value> *node);

  Node<Key, Value> *insert(const Key &key, const Value &value,
                           bool need_assign);
  Node<Key, Value> *begin();
  Node<Key, Value> *end();
  void erase(Node<Key, Value> *pos);

  Node<Key, Value> *root;
  Node<Key, Value> *fake;
  size_t _size;

  class Iterator {
   public:
    Iterator(Node<Key, Value> *node, RBTree<Key, Value> *tree)
        : node(node), tree(tree){};
    Node<Key, Value> *node;
    RBTree<Key, Value> *tree;

    ~Iterator() = default;

    std::pair<const Key, Value> operator*() {
      return std::pair<const Key, Value>(node->key, node->value);
    }

    Iterator operator++() {
      if (node == tree->fake) {
        throw std::out_of_range("out of container range");
      } else if (node == tree->find_max(this->tree->root)) {
        node = tree->fake;
      } else if (node->next != nullptr) {
        node = node->next;
      } else {
        while (node->prev != nullptr) {
          node = node->prev;
        }
        if (node->right) {
          node = node->right;
          while (node->left) {
            node = node->left;
          }
        } else {
          Node<Key, Value> *parent = node->parent;
          while (node == parent->right) {
            node = parent;
            parent = parent->parent;
          }
          if (node->right != parent) node = parent;
        }
      }
      return *this;
    }

    Iterator operator--() {
      if (node == tree->fake) {
        node = tree->fake->prev;
      } else if (node->prev != nullptr) {
        node = node->prev;
      } else {
        if (node->left) {
          node = node->left;
          while (node->right) {
            node = node->right;
          }
        } else {
          Node<Key, Value> *parent = node->parent;
          while (node == parent->left) {
            node = parent;
            parent = parent->parent;
          }
          if (node->left != parent) node = parent;
        }
        while (node->next != nullptr) {
          node = node->next;
        }
      }
      return *this;
    }

    bool operator==(const Iterator &other) const {
      return this->node == other.node;
    }

    bool operator!=(const Iterator &other) const {
      return this->node != other.node;
    }
  };

  class ConstIterator : Iterator {
   public:
    ConstIterator(RBTree<Key, Value> *tree) : node(tree->root){};
    Node<Key, Value> *node;
  };
};

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() : root(nullptr), _size(0) {
  fake = new Node<Key, Value>();
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(
    std::initializer_list<std::pair<const Key, Value>> const &items)
    : root(nullptr), _size(0) {
  fake = new Node<Key, Value>();
  for (std::pair<const Key, Value> value : items) {
    insert(value.first, value.second, false);
  }
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(const RBTree<Key, Value> &tree)
    : root(nullptr), _size(0) {
  fake = tree.fake;
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    insert(it->node->key, it->node->value, false);
  }
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(RBTree &&tree) {
  *this = std::move(tree);
}

template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree() {
  delete root;
  delete fake;
};

template <typename Key, typename Value>
RBTree<Key, Value> &RBTree<Key, Value>::operator=(const RBTree &&t) {
  if (this != &t) {
    root = t.root;
    t.root = nullptr;
  }
  return *this;
}

template <typename Key, typename Value>
RBTree<Key, Value> &RBTree<Key, Value>::operator=(const RBTree &t) {
  if (this != &t) {
    root = t.root;
    _size = t._size;
  }
  return *this;
}

template <typename Key, typename Value>
Node<Key, Value> *RBTree<Key, Value>::insert(const Key &key, const Value &value,
                                             bool need_assign) {
  Node<Key, Value> *new_node = nullptr;
  Node<Key, Value> *prev = nullptr;
  Node<Key, Value> *next = root;
  bool exist = false;

  while (next != nullptr) {
    prev = next;
    if (need_assign && key == next->key) {
      exist = true;
      next->value = need_assign ? value : next->value;
      break;
    }
    if (key < next->key) {
      next = next->left;
    } else {
      next = next->right;
    }
  }

  if (!exist) {
    new_node = new Node<Key, Value>(key, value, RED);
    new_node->parent = prev;

    if (prev == nullptr) {
      root = new_node;
    } else if (key < prev->key) {
      prev->left = new_node;
    } else {
      prev->right = new_node;
    }

    balance(new_node);
    this->_size++;
  }

  fake->prev = find_max(this->root);
  return exist ? prev : new_node;
}
template <typename Key, typename Value>
bool RBTree<Key, Value>::contains(const Key &key) {
  bool result = false;
  if (find(key) != nullptr) {
    result = true;
  }
  return result;
};

template <typename Key, typename Value>
bool RBTree<Key, Value>::is_empty() {
  return !root;
};

template <typename Key, typename Value>
size_t RBTree<Key, Value>::size() {
  return _size;
};

template <typename Key, typename Value>
size_t RBTree<Key, Value>::max_size() {
  return (size_t)-1;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::rotate_right(Node<Key, Value> *node) {
  Node<Key, Value> *node_left = node->left;
  node->left = node_left->right;
  if (node_left->right != nullptr) {
    node_left->right->parent = node;
  }
  node_left->parent = node->parent;
  if (node->parent == nullptr) {
    root = node_left;
  } else if (node == node->parent->right) {
    node->parent->right = node_left;
  } else {
    node->parent->left = node_left;
  }
  node_left->right = node;
  node->parent = node_left;
};

template <typename Key, typename Value>
void RBTree<Key, Value>::rotate_left(Node<Key, Value> *node) {
  Node<Key, Value> *node_right = node->right;
  node->right = node_right->left;
  if (node_right->left != nullptr) {
    node_right->left->parent = node;
  }
  node_right->parent = node->parent;
  if (node->parent == nullptr) {
    root = node_right;
  } else if (node == node->parent->left) {
    node->parent->left = node_right;
  } else {
    node->parent->right = node_right;
  }
  node_right->left = node;
  node->parent = node_right;
};

template <typename Key, typename Value>
void RBTree<Key, Value>::balance(Node<Key, Value> *node) {
  while (node->parent != nullptr && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) {
      Node<Key, Value> *uncle = node->parent->parent->right;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else if (node == node->parent->right) {
        node = node->parent;
        rotate_left(node);
      } else {
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        rotate_right(node->parent->parent);
      }
    } else {
      Node<Key, Value> *uncle = node->parent->parent->left;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else if (node == node->parent->left) {
        node = node->parent;
        rotate_right(node);
      } else {
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        rotate_left(node->parent->parent);
      }
    }
  }
  root->color = BLACK;
};

template <typename Key, typename Value>
void RBTree<Key, Value>::transplant(Node<Key, Value> *node,
                                    Node<Key, Value> *child) {
  if (node->parent == nullptr) {
    root = child;
  } else if (node == node->parent->left) {
    node->parent->left = child;
  } else {
    node->parent->right = child;
  }
};

template <typename Key, typename Value>
void RBTree<Key, Value>::delete_node(Node<Key, Value> *node) {
  Color origin = node->color;
  if (node->left == nullptr) {
    transplant(node, node->right);
    delete node;
  } else if (node->right == nullptr) {
    transplant(node, node->left);
    delete node;
  } else {
    Node<Key, Value> *min = find_min(node->right);
    origin = min->color;
    Node<Key, Value> *loc_min_r = min->right;
    if (min->parent == node) {
      loc_min_r->parent = min;
    } else {
      transplant(min, min->right);
      min->right = node->right;
      min->right->parent = min;
      transplant(node, min);
      min->left = node->left;
      min->left->parent = min;
      min->color = node->color;
      node->left = nullptr;
      node->right = nullptr;
      delete node;
    }
    if (origin == BLACK) fix_delete(loc_min_r);
  }
};

template <typename Key, typename Value>
void RBTree<Key, Value>::fix_delete(Node<Key, Value> *node) {
  while (node != root && node->color == BLACK) {
    if (node == node->parent->left) {
      Node<Key, Value> *sibl = node->parent->right;
      if (sibl->color == RED) {
        sibl->color = BLACK;
        node->parent->color = RED;
        rotate_left(node->parent);
        sibl = node->parent->right;
      }
      if (sibl->left->color == BLACK && sibl->right->color == BLACK) {
        sibl->color = RED;
        Node<Key, Value> *tmp = node;
        node = node->parent;
        delete tmp;
      } else {
        if (sibl->right->color == BLACK) {
          sibl->left->color = BLACK;
          sibl->color = RED;
          rotate_right(sibl);
          sibl = node->parent->right;
        }
        sibl->color = node->parent->color;
        node->parent->color = BLACK;
        sibl->right->color = BLACK;
        rotate_left(node->parent);
        Node<Key, Value> *tmp = node;
        node = root;
        delete tmp;
      }
    }
  }
  node->color = BLACK;
};

template <typename Key, typename Value>
Node<Key, Value> *RBTree<Key, Value>::find_min(Node<Key, Value> *node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
};

template <typename Key, typename Value>
Node<Key, Value> *RBTree<Key, Value>::find_max(Node<Key, Value> *node) {
  while (node->right != nullptr) {
    node = node->right;
  }
  while (node->next != nullptr) {
    node = node->next;
  }
  return node;
};

template <typename Key, typename Value>
typename s21::Node<Key, Value> *RBTree<Key, Value>::begin() {
  Node<Key, Value> *node;
  if (_size == 0) {
    node = fake;
  } else {
    node = find_min(this->root);
  }
  while (node->next) {
    node = node->prev;
  }
  return node;
};

template <typename Key, typename Value>
typename s21::Node<Key, Value> *RBTree<Key, Value>::end() {
  return fake;
};

template <typename Key, typename Value>
void RBTree<Key, Value>::erase(Node<Key, Value> *pos) {
  delete_node(pos);
  _size--;
  fake->prev = find_max(this->root);
};

template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {
  delete root;
  root = nullptr;
  fake->prev = nullptr;
};

template <typename Key, typename Value>
void RBTree<Key, Value>::swap(RBTree<Key, Value> &other) {
  Node<Key, Value> *tmp_root = root;
  Node<Key, Value> *tmp_fake = fake;
  size_t tmp_size = _size;
  root = other.root;
  fake = other.fake;
  _size = other._size;
  other.root = tmp_root;
  other.fake = tmp_fake;
  other._size = tmp_size;
};

template <typename Key, typename Value>
Value &RBTree<Key, Value>::at(const Key &key) {
  Node<Key, Value> *result;
  if (this->contains(key)) {
    result = find(key);
  } else {
    throw std::out_of_range("Key does not exist");
  }
  return result->value;
};

template <typename Key, typename Value>
Value &RBTree<Key, Value>::operator[](const Key &key) {
  if (!this->contains(key)) {
    this->insert(key, Value(), false);
  }
  return this->at(key);
};

template <typename Key, typename Value>
Node<Key, Value> *RBTree<Key, Value>::find(const Key &key) {
  Node<Key, Value> *result = nullptr;
  if (root != nullptr) {
    Node<Key, Value> *cur_node = root;
    while (cur_node != nullptr) {
      if (cur_node->key == key) {
        while (cur_node->next != nullptr) {
          cur_node = cur_node->next;
        }
        result = cur_node;
        break;
      } else if (cur_node->key < key) {
        cur_node = cur_node->right;
      } else {
        cur_node = cur_node->left;
      }
    }
  }
  return result;
};
}  // namespace s21
