cmake_minimum_required(VERSION 3.10)
project(kruskal_v2 C)

set(CMAKE_C_STANDARD 99)

add_executable(kruskal_v2 main.c mst.c mst.h)