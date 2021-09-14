#include "MyVector.h"
#include "gtest/gtest.h"

TEST(test_size, init_vector) {
  MyVector<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(test_size, after_push_back) {
  MyVector<int> v;
  for (size_t i = 0; i < 10; i++) {
    v.push_back(i);
  }
  EXPECT_EQ(v.size(), 10);
}

TEST(test_operator_scopes, get_by_index) {
  MyVector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(15);
  EXPECT_EQ(v[1], 10);
  EXPECT_EQ(v[0], 5);
}

TEST(test_operator_scopes, modify_by_reference) {
  MyVector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(15);
  v[1] = 100;
  EXPECT_EQ(v[1], 100);
}

TEST(test_operator_scopes, throw_exception_out_of_range) {
  MyVector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(15);
  EXPECT_THROW({
   try {
     int value = v[10];
   } catch (const std::out_of_range &ex) {
     throw;
   }
  }, std::out_of_range);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

