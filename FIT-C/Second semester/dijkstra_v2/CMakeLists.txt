cmake_minimum_required(VERSION 3.10)
project(dijkstra_v2 C)

set(CMAKE_C_STANDARD 99)

add_executable(dijkstra_v2 main.c Graph.c Graph.h Edge.c Edge.h priority_queue.c priority_queue.h)