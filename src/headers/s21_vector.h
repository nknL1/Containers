#pragma once

#include <stddef.h>

#include <initializer_list>
#include <iostream>
#include <limits>
#include <utility>

namespace s21 {

template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector() : data_(nullptr), size_(0), capacity_(0) {}
  vector(size_type n) {
    data_ = new value_type[n];
    size_ = n;
    capacity_ = n;
  }
  vector(std::initializer_list<value_type> const &items) {
    data_ = new value_type[items.size()];
    size_ = items.size();
    capacity_ = items.size();
    std::copy(items.begin(), items.end(), data_);
  }
  vector(const vector &v) {
    data_ = new value_type[v.capacity_];
    size_ = v.size_;
    capacity_ = v.capacity_;
    std::copy(v.data_, v.data_ + v.capacity_, data_);
  }
  vector(vector &&v) {
    data_ = v.data_;
    v.data_ = nullptr;
    size_ = v.size_;
    v.size_ = 0;
    capacity_ = v.capacity_;
    v.capacity_ = 0;
  };
  ~vector() {
    if (data_ != nullptr) {
      delete[] data_;
    }
    data_ = nullptr;
  }
  vector &operator=(vector &&v) {
    if (this != &v) {
      if (data_ != nullptr) {
        delete[] data_;
      }
      data_ = v.data_;
      v.data_ = nullptr;
      size_ = v.size_;
      v.size_ = 0;
      capacity_ = v.capacity_;
      v.capacity_ = 0;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("index out of range");
    }
    return data_[pos];
  }
  reference operator[](size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("index out of range");
    }
    return data_[pos];
  }
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
  T *data() { return data_; }

  iterator begin() { return data_; }
  iterator end() { return data_ + size_; }

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  }
  void reserve(size_type size) {
    if (size <= capacity_) return;
    if (size > max_size()) {
      throw std::length_error("new size is too big");
    }
    value_type *new_data = new value_type[size];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
  }
  size_type capacity() { return capacity_; }
  void shrink_to_fit() {
    vector<value_type> temp(size_);
    for (size_type i = 0; i < size_; i++) {
      temp.data_[i] = data_[i];
    }
    *this = std::move(temp);
  }

  void clear() {
    if (data_ != nullptr) {
      delete[] data_;
    }
    data_ = nullptr;
    size_ = 0;
  }
  iterator insert(iterator pos, const_reference value) {
    size_type index = pos - begin();
    if (index > size_) {
      throw std::out_of_range("invalid iterator position");
    }
    if (size_ == capacity_) {
      reserve(capacity_ * 2 + 1);
    }
    std::copy_backward(data_ + index, data_ + size_, data_ + size_ + 1);
    data_[index] = value;
    size_++;
    return iterator(data_ + index);
  }
  void erase(iterator pos) {
    size_type index = pos - data_;
    if (index >= size_) {
      throw std::out_of_range("index out of range");
    }
    for (size_type i = index; i < size_ - 1; i++) {
      data_[i] = data_[i + 1];
    }
    size_--;
  }
  void push_back(const_reference value) {
    if (size_ >= capacity_) {
      reserve(capacity_ * 2 + 1);
    }
    data_[size_] = value;
    size_++;
  }
  void pop_back() {
    if (size_ > 0) {
      size_--;
    }
  }
  void swap(vector &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    if (pos < begin() || pos > end()) {
      throw std::out_of_range("index out of range");
    }
    vector<value_type> temp{args...};
    iterator cpos = begin() + (pos - begin());
    for (size_type i = 0; i < temp.size(); ++i) {
      cpos = insert(cpos, temp[i]);
      cpos++;
    }
    return cpos;
  }
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    vector<value_type> temp{args...};
    for (size_type i = 0; i < temp.size_; i++) {
      push_back(temp.data_[i]);
    }
  }

 private:
  value_type *data_;
  size_type size_;
  size_type capacity_;
};

}  // namespace s21