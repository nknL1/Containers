#pragma once

#include <stddef.h>

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <typename T, std::size_t N>
class array {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

 public:
  array() : size_(0) {}

  array(std::initializer_list<value_type> const& items) : size_(0) {
    size_type i = 0;
    for (auto it = items.begin(); it != items.end(); ++it, ++i) {
      if (i >= N) {
        throw std::out_of_range("Initializer list too long");
      }
      data_[i] = *it;
    }
    size_ = i;
  }

  array(const array& a) : size_(a.size_) {
    std::copy(a.data_, a.data_ + a.size_, data_);
  }

  array(array&& a) : size_(a.size_) {
    std::copy(a.data_, a.data_ + a.size_, data_);
    a.size_ = 0;
  }

  ~array() {}

  array& operator=(array&& a) {
    if (this != &a) {
      std::copy(a.data_, a.data_ + a.size_, data_);
      size_ = a.size_;
      a.size_ = 0;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("index out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference front() {
    if (size_ == 0) {
      throw std::out_of_range("index out of range");
    }
    return data_[0];
  }

  const_reference back() {
    if (size_ == 0) {
      throw std::out_of_range("index out of range");
    }
    return data_[size_ - 1];
  }

  iterator data() { return data_; }

  iterator begin() { return data_; }

  iterator end() { return data_ + size_; }

  bool empty() { return size_ == 0; }

  size_type size() { return size_; }

  size_type max_size() { return N; }

  void swap(array& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = value;
    }
    size_ = N;
  }

 private:
  value_type data_[N];
  size_type size_ = 0;
};
}  // namespace s21