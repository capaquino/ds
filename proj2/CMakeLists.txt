cmake_minimum_required(VERSION 3.9)
project(project2)

set(CMAKE_CXX_STANDARD 11)
set (INPUT_FILE input)

add_executable(project2 main.cpp directedgraph.cpp vertex.cpp)

configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_FILE} COPYONLY)
