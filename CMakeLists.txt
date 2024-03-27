cmake_minimum_required(VERSION 3.16.3)
project(untitled4 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled4 main.c polinomio.h polinomio.c lista.h lista.c)

target_link_libraries(untitled4 m)