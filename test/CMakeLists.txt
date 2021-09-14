add_executable(test_vector test.cpp)
target_link_libraries(test_vector gtest)

add_test(test_vector test_vector)

