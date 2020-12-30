cmake_minimum_required(VERSION 3.17)
project(Cache_Oblivious_Algorithm_Test)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Cache_Oblivious_Algorithm_Test src/main.cpp src/matrix.cpp src/matrix.h)