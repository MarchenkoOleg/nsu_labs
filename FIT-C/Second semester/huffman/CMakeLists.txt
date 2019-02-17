cmake_minimum_required(VERSION 3.10)
project(huffman C)

set(CMAKE_C_STANDARD 99)

add_executable(huffman main.c bitio.c bitio.h priorityQueue.c priorityQueue.h tree.c tree.h types.c types.h algorithmFunctions.c algorithmFunctions.h)