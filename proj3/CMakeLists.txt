cmake_minimum_required(VERSION 3.9)
project(project3)

set(CMAKE_CXX_STANDARD 11)
set (INPUT_FILE input)

add_executable(project3 316p3.cpp)

configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_FILE} COPYONLY)
