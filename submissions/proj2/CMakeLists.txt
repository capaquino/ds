cmake_minimum_required(VERSION 3.9)
project(proj2)

set(CMAKE_CXX_STANDARD 11)
set (INPUT_FILE input)

add_executable(proj2 3648_316p2.cpp)

configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_FILE} COPYONLY)
