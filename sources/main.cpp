#include <iostream>
#include <algorithm>
#include <random>
#include "MyVector.h"

int main() {
  MyVector<int> v;
  std::mt19937 rand(42);
  for (int i = 0; i < 10; i++) {
    v.push_back(rand() % 100);
  }
  std::cout << v << "\n";
  std::sort(v.begin(), v.end());
  std::cout << v << "\n";
  try {
    v[15] = 100;
  } catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
  }
  return 0;
}