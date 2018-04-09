cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

project(horse)
add_executable(horse main.cc)
