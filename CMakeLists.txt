cmake_minimum_required(VERSION 3.6)
project(openmp)


SET(CMAKE_C_COMPILER C:\\MinGW\\bin\\gcc)
SET(CMAKE_CXX_COMPILER C:\\MinGW\\bin\\g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp
        PiCalculator.h
        PiCalculator.cpp Sort.cpp Sort.h)
add_executable(openmp ${SOURCE_FILES})