#pragma once

#include <stddef.h>

#include <initializer_list>
#include <utility>

namespace s21 {
template <class T>
class queue {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct node {
    value_type value;
    node* next;
  };
  node* head_;
  node* tail_;
  size_type size_;

 public:
  queue() : head_(nullptr), tail_(nullptr), size_(0) {}
  queue(std::initializer_list<value_type> const& items)
      : head_(nullptr), tail_(nullptr), size_(0) {
    for (auto it = items.begin(); it != items.end(); ++it) {
      node* temp = new node;
      temp->value = *it;
      temp->next = nullptr;
      if (head_ == nullptr) {
        head_ = temp;
        tail_ = temp;
      } else {
        tail_->next = temp;
        tail_ = temp;
      }
      size_++;
    }
  }

  queue(const queue& q) : head_(nullptr), tail_(nullptr), size_(0) {
    node* current = q.head_;
    while (current != nullptr) {
      push(current->value);
      current = current->next;
    }
  }

  queue(queue&& q) : head_(q.head_), tail_(q.tail_), size_(q.size_) {
    q.head_ = nullptr;
    q.tail_ = nullptr;
    q.size_ = 0;
  }

  ~queue() {
    while (head_ != nullptr) {
      node* temp = head_;
      head_ = head_->next;
      delete temp;
    }
  }

  queue& operator=(queue&& q) {
    if (this != &q) {
      while (head_ != nullptr) {
        node* temp = head_;
        head_ = head_->next;
        delete temp;
      }
      head_ = q.head_;
      tail_ = q.tail_;
      size_ = q.size_;
      q.head_ = nullptr;
      q.tail_ = nullptr;
      q.size_ = 0;
    }
    return *this;
  }

  queue& operator=(const queue& q) {
    if (this != &q) {
      while (head_ != nullptr) {
        node* temp = head_;
        head_ = head_->next;
        delete temp;
      }
      node* current = q.head_;
      while (current != nullptr) {
        push(current->value);
        current = current->next;
      }
    }
    return *this;
  }

  const_reference front() { return head_->value; }

  const_reference back() { return tail_->value; }

  bool empty() { return size_ == 0; }

  size_type size() { return size_; }

  void push(const_reference value) {
    node* new_node = new node;
    new_node->value = value;
    new_node->next = nullptr;
    if (head_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      tail_->next = new_node;
      tail_ = new_node;
    }
    size_++;
  }

  void pop() {
    if (head_ != nullptr) {
      node* temp = head_;
      head_ = head_->next;
      delete temp;
      size_--;
    }
  }

  void swap(queue& other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }
};
}  // namespace s21