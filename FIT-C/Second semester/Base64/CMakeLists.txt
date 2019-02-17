cmake_minimum_required(VERSION 3.9)
project(base64 C)

set(CMAKE_C_STANDARD 99)

add_executable(base64 main.c base64coder.c base64coder.h)