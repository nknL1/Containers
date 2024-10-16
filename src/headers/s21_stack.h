#pragma once

#include <stddef.h>

#include <initializer_list>
#include <utility>
namespace s21 {
template <class T>
class stack {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct node {
    value_type value;
    node* next;
  };
  node* top_;
  size_type size_;

  void copy_from(const stack& s) {
    if (s.top_ == nullptr) {
      top_ = nullptr;
      size_ = 0;
    } else {
      top_ = new node{s.top_->value, nullptr};
      node* current = top_;
      node* s_current = s.top_->next;
      while (s_current != nullptr) {
        current->next = new node{s_current->value, nullptr};
        current = current->next;
        s_current = s_current->next;
      }
      size_ = s.size_;
    }
  }

 public:
  stack() : top_(nullptr), size_(0) {}
  stack(std::initializer_list<value_type> const& items)
      : top_(nullptr), size_(0) {
    for (auto it = items.begin(); it != items.end(); ++it) {
      push(*it);
    }
  }
  stack(const stack& s) : top_(nullptr), size_(0) { copy_from(s); }
  stack(stack&& s) noexcept : top_(s.top_), size_(s.size_) {
    s.top_ = nullptr;
    s.size_ = 0;
  }
  ~stack() {
    while (top_ != nullptr) {
      node* temp = top_;
      top_ = top_->next;
      delete temp;
    }
  }

  const_reference top() const { return top_->value; }

  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }

  void push(const_reference value) {
    node* new_node = new node{value, top_};
    top_ = new_node;
    ++size_;
  }
  void pop() {
    if (top_ != nullptr) {
      node* temp = top_;
      top_ = top_->next;
      delete temp;
      --size_;
    }
  }

  stack& operator=(const stack& s) {
    if (this != &s) {
      while (top_ != nullptr) {
        node* temp = top_;
        top_ = top_->next;
        delete temp;
      }
      copy_from(s);
    }
    return *this;
  }

  stack& operator=(stack&& s) {
    if (this != &s) {
      while (top_ != nullptr) {
        node* temp = top_;
        top_ = top_->next;
        delete temp;
      }
      top_ = s.top_;
      size_ = s.size_;
      s.top_ = nullptr;
      s.size_ = 0;
    }
    return *this;
  }

  void swap(stack& other) noexcept {
    std::swap(top_, other.top_);
    std::swap(size_, other.size_);
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }
};
}  // namespace s21
