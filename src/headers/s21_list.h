#pragma once

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = std::size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& other);
  list(list&& other);

  virtual ~list();

  size_type max_size();
  size_type size();
  iterator insert(iterator pos, const_reference value);
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);
  template <typename... Args>
  void insert_many_front(Args&&... args);
  const_iterator cend() const;
  const_reference front();
  const_reference back();
  bool empty();
  void splice(const_iterator pos, list& other);
  void unique();
  void merge(list& other);
  void sort();
  void erase(iterator pos);
  void clear();
  void reverse();
  void swap(list& other);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  template <typename... Args>
  void emplace_back(Args&&... args);
  template <typename... Args>
  void emplace_front(Args&&... args);
  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);

  list& operator=(const list& other);
  list& operator=(list&& other);

 private:
  class Node {
   public:
    explicit Node(const value_type& d = value_type{}, Node* p = nullptr,
                  Node* n = nullptr)
        : data(d), prev(p), next(n) {}
    value_type data{};
    Node* prev;
    Node* next;
  };

  Node* head{nullptr};
  Node* tail{nullptr};
};

template <typename value_type>
class list<value_type>::ListIterator {
 public:
  friend class list;

  ListIterator() = default;
  ListIterator(const ListConstIterator& it) : node_(it.it_.node_) {}
  ListIterator(Node* node, Node* head, Node* tail)
      : node_(node), head_(head), tail_(tail) {}

  ListIterator& operator++() {
    if (head_ != nullptr) {
      if (node_ != nullptr) {
        node_ = node_->next;
      } else {
        node_ = head_;
      }
    }
    return *this;
  }

  ListIterator& operator--() {
    if (tail_ != nullptr) {
      if (node_ != nullptr) {
        if (node_->prev != nullptr) {
          node_ = node_->prev;
        } else {
          node_ = tail_->next;
        }
      } else {
        node_ = tail_;
      }
    }
    return *this;
  }

  ListIterator operator++(int) {
    ListIterator it(*this);
    ++(*this);
    return it;
  }

  ListIterator operator--(int) {
    ListIterator it(*this);
    --(*this);
    return it;
  }

  bool operator==(const ListIterator& other) const {
    return node_ == other.node_;
  }

  bool operator!=(const ListIterator& other) const { return !(*this == other); }

  ListIterator operator+(size_type n) const {
    ListIterator it(*this);
    for (; n != 0; --n) ++it;
    return it;
  }

  ListIterator operator-(size_type n) const {
    ListIterator it(*this);
    for (; n != 0; --n) --it;
    return it;
  }

  reference operator*() const {
    if (node_ == nullptr && tail_ != nullptr) {
      return tail_->data;
    } else if (node_ != nullptr) {
      return node_->data;
    } else {
      throw std::invalid_argument("Invalid index");
    }
  }

 private:
  Node* node_{nullptr};
  Node* head_{nullptr};
  Node* tail_{nullptr};
};

template <typename value_type>
class list<value_type>::ListConstIterator : public ListIterator {
 public:
  friend class list;

  ListConstIterator() = default;
  ListConstIterator(const ListIterator& it) : it_(it) {}
  ListConstIterator(Node* node, Node* head = nullptr, Node* tail = nullptr)
      : it_(node, head, tail) {}

  ListConstIterator& operator++() {
    ++it_;
    return *this;
  }

  ListConstIterator& operator--() {
    --it_;
    return *this;
  }

  ListConstIterator operator++(int) {
    ListConstIterator result(*this);
    ++it_;
    return result;
  }

  ListConstIterator operator--(int) {
    ListConstIterator result(*this);
    --it_;
    return result;
  }

  bool operator==(const ListConstIterator& other) const {
    return it_ == other.it_;
  }

  bool operator!=(const ListConstIterator& other) const {
    return !(it_ == other.it_);
  }

  const_reference operator*() const { return *it_; }

 private:
  ListIterator it_;
};

template <typename value_type>
list<value_type>::list() : head(nullptr), tail(nullptr) {}

template <typename value_type>
list<value_type>::list(size_type n) {
  for (; n > 0; --n) {
    push_back(value_type{});
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items) {
  for (auto& i : items) {
    push_back(i);
  }
}

template <typename value_type>
list<value_type>::list(const list& other) {
  for (const_iterator it = other.cbegin(); it != other.cend(); ++it) {
    push_back(*it);
  }
}

template <typename value_type>
list<value_type>::list(list&& other) {
  swap(other);
}

template <typename value_type>
list<value_type>::~list() {
  while (head != nullptr) pop_front();
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
#ifdef __APPLE__
  return std::numeric_limits<size_type>::max() / sizeof(Node);
#else
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
#endif
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  size_type n = 0;
  for (iterator it = begin(); it != end(); ++it) {
    ++n;
  }
  return n;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  if (empty() || pos == end()) {
    push_back(value);
    return iterator(tail);
  } else if (pos == begin()) {
    push_front(value);
    return iterator(head);
  } else {
    Node* nextNode = pos.node_;
    Node* prevNode = pos.node_->prev;
    Node* newNode = new Node(value, prevNode, nextNode);

    prevNode->next = newNode;
    nextNode->prev = newNode;

    return iterator(newNode);
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  if (empty()) {
    return iterator(head);
  } else {
    return iterator(head, head, tail);
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  if (empty()) {
    return iterator(tail);
  } else {
    return iterator(tail->next, head, tail);
  }
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin() const {
  if (head != nullptr) {
    return const_iterator(head, head, tail);
  } else {
    return const_iterator(nullptr);
  }
}

template <typename value_type>
template <typename... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    const_iterator pos, Args&&... args) {
  for (const auto& arg : {args...}) {
    insert(pos, arg);
  }
  return this->begin();
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_back(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_back(arg);
  }
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_front(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_front(arg);
  }
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend() const {
  if (tail != nullptr) {
    return const_iterator(tail->next, head, tail);
  } else {
    return const_iterator(nullptr);
  }
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  if (empty()) {
    static const_reference default_value{};
    return default_value;
  } else {
    return *begin();
  }
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  if (empty()) {
    static const_reference default_value{};
    return default_value;
  } else {
    return *(--end());
  }
}

template <typename value_type>
bool list<value_type>::empty() {
  return head == nullptr && tail == nullptr;
}

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) {
  if (!other.empty()) {
    if (!empty()) {
      if (pos.it_.node_ == tail->next) {
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
      } else if (pos.it_.node_ == head) {
        head->prev = other.tail;
        other.tail->next = head;
        head = other.head;
      } else if (!empty()) {
        Node* start_dest = pos.it_.node_->prev;
        Node* end_dest = pos.it_.node_;

        start_dest->next = other.head;
        end_dest->prev = other.tail;
        other.head->prev = start_dest;
        other.tail->next = end_dest;
      }
      other.head = nullptr;
      other.tail = nullptr;
    } else {
      swap(other);
    }
  }
}

template <typename value_type>
void list<value_type>::unique() {
  for (iterator it = ++begin(); it != end(); ++it) {
    if (*it == *(it - 1)) {
      erase(it - 1);
    }
  }
}

template <typename value_type>
void list<value_type>::merge(list& other) {
  list tempList(*this);
  iterator it_L1 = tempList.begin();
  iterator it_L2 = other.begin();

  clear();
  while (it_L1 != tempList.end() && it_L2 != other.end()) {
    if (*it_L1 < *it_L2) {
      push_back(*it_L1);
      tempList.erase(it_L1++);
    } else {
      push_back(*it_L2);
      other.erase(it_L2++);
    }
  }
  splice(end(), tempList);
  splice(end(), other);
}

template <typename value_type>
void list<value_type>::sort() {
  for (iterator it_i = ++begin(); it_i != end(); ++it_i) {
    value_type key = *it_i;
    iterator it_j = it_i - 1;

    for (; it_j.node_ != nullptr && *it_j > key; --it_j) {
      *(it_j + 1) = *it_j;
    }
    *(it_j + 1) = key;
  }
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos.node_ == nullptr) {
    std::cerr << "Invalid pointer" << std::endl;
    std::abort();
  } else {
    if (pos.node_ == head) {
      pop_front();
    } else if (pos.node_->next == tail->next) {
      pop_back();
    } else {
      Node* temp = pos.node_;
      Node* prevNode = pos.node_->prev;
      Node* nextNode = pos.node_->next;

      prevNode->next = nextNode;
      nextNode->prev = prevNode;
      delete temp;
    }
  }
}

template <typename value_type>
void list<value_type>::clear() {
  this->~list();
}

template <typename value_type>
void list<value_type>::reverse() {
  iterator it_left = begin();
  iterator it_right = --end();

  for (size_type i = 0; i < size() / 2; i++, ++it_left, --it_right) {
    std::swap(*it_left, *it_right);
  }
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  if (this != &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
  }
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  if (tail == nullptr) {
    tail = head = new Node(value);
  } else {
    tail->next = new Node(value, tail);
    tail = tail->next;
  }
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (tail != nullptr) {
    Node* temp = tail;

    tail = tail->prev;
    if (tail != nullptr) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }
    delete temp;
  }
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  if (head == nullptr) {
    head = tail = new Node(value);
  } else {
    head->prev = new Node(value, nullptr, head);
    head = head->prev;
  }
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (head != nullptr) {
    Node* temp = head;

    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
  }
}

template <typename value_type>
template <typename... Args>
void list<value_type>::emplace_back(Args&&... args) {
  emplace(end(), args...);
}

template <typename value_type>
template <typename... Args>
void list<value_type>::emplace_front(Args&&... args) {
  emplace(begin(), args...);
}

template <typename value_type>
template <typename... Args>
typename list<value_type>::iterator list<value_type>::emplace(
    const_iterator pos, Args&&... args) {
  auto args_list =
      std::initializer_list<value_type>{std::forward<Args>(args)...};

  for (auto& i : args_list) {
    insert(pos, i);
  }
  return pos;
}

template <typename value_type>
list<value_type>& list<value_type>::operator=(const list& other) {
  if (this != &other) {
    clear();
    new (this) list(other);
  }
  return *this;
}

template <typename value_type>
list<value_type>& list<value_type>::operator=(list&& other) {
  if (this != &other) {
    clear();
    new (this) list(std::move(other));
  }
  return *this;
}

}  // namespace s21
