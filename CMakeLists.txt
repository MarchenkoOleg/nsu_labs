cmake_minimum_required(VERSION 3.12)
project(17209_marchenko_HashTable)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(libs/googletest)
include_directories(libs/googletest/include)
add_executable(17209_marchenko_HashTable main.cpp HashTable.cpp HashTable.h)
target_link_libraries(17209_marchenko_HashTable gtest gtest_main)