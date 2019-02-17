cmake_minimum_required(VERSION 3.9)
project(graph_dfs C)

set(CMAKE_C_STANDARD 99)

add_executable(graph_dfs main.c stack.c stack.h tolological_sort.c tolological_sort.h)