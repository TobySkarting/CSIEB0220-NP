cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

project(mymaze)
add_executable(mymaze main.cc maze.cc player.cc room.cc)
