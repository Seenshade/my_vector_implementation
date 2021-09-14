cmake_minimum_required(VERSION 3.19)
project(VectorImplementation)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(third_party/googletest)
enable_testing()

include_directories(sources)

add_subdirectory(sources)

add_subdirectory(test)

