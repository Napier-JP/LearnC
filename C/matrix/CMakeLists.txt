cmake_minimum_required(VERSION 3.14)
project(LearnC C)

set(CMAKE_C_STANDARD 99)

add_executable(LearnC matrix_main.c matrix.h matrix.c)