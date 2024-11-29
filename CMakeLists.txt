cmake_minimum_required(VERSION 3.29)
project(graph_shortest_path)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph_shortest_path bellman-ford.c)
