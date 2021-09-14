#pragma once

#include "iostream"
#include "cmath"

template<typename T>
class MyVector {
private:
  unsigned long long _size, _capacity;
  T *data;

  void Reallocate(unsigned long long new_capacity) {
    T *new_data = new T[new_capacity];
    if (_capacity > 1) {
      for (unsigned long long i = 0; i < _size; i++) {
        new_data[i] = data[i];
      }
      delete[] data;
    } else {
      *new_data = *data;
      delete data;
    }
    _capacity = new_capacity;
    data = new_data;
  }

public:
  MyVector()
    : _size(0),
      _capacity(0),
      data(nullptr) {}

  explicit MyVector(unsigned long long size)
    : _size(size),
      _capacity(size),
      data(new T[size]) {}

  ~MyVector() {
    if (_capacity > 1) {
      delete[] data;
    } else {
      delete data;
    }
  }

  void push_back(const T &value) {
    if (data == nullptr) {
      data = new T(value);
      _capacity = 1;
    } else {
      if (_size == _capacity) {
        Reallocate(std::ceil(1.6 * _capacity));
      }
    }
    data[_size] = value;
    _size++;
  }

  void push_back(T &&value) {
    if (data == nullptr) {
      data = new T(std::forward<T>(value));
      _capacity = 1;
    } else {
      if (_size == _capacity) {
        Reallocate(std::ceil(1.6 * _capacity));
      }
    }
    data[_size] = std::move(value);
    _size++;
  }

  T &operator[](unsigned long long idx) {
    if (idx > _capacity - 1) {
      throw std::out_of_range("out of range element access");
    }
    return data[idx];
  }

  T *begin() {
    return data;
  }

  T *begin() const {
    return data;
  }

  T *end() {
    return data + _size;
  }

  T *end() const {
    return data + _size;
  }

  unsigned long long size() const {
    return _size;
  }

  unsigned long long capacity() const {
    return _capacity;
  }

};

template<typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &v) {
  bool first = true;
  os << "[";
  for (const auto &value : v) {
    if (!first) {
      os << ", ";
    }
    os << value;
    first = false;
  }
  os << "]";
  return os;
}