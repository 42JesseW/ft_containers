cmake_minimum_required(VERSION 3.17)
project(ft_containers CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(HEADERS includes srcs/vector srcs/stack srcs/map srcs/iterator)

include_directories(${HEADERS})

add_subdirectory(tests)
