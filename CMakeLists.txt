cmake_minimum_required(VERSION 3.15)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)

add_executable(GameOfLife main.c validation.c libvalidate.h visualization.c libvisual.h generation.c libgenerate.h)