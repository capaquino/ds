cmake_minimum_required(VERSION 3.9)
project(project4)

set(CMAKE_CXX_STANDARD 11)
set (INPUT_FILE cs316p4.txt)

add_executable(project4 3648_316p4.cpp)

configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_FILE} COPYONLY)
