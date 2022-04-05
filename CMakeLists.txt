cmake_minimum_required(VERSION 3.10)

project(LearnCPP)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -g -O2 -Wall)

# set(CMAKE_BUILD_TYPE Debug)

set(Bookstore src/IOStream/Bookstore/Bookstore.cpp)

set(EXECUTABLE_OUTPUT_PATH ${LearnCPP_SOURCE_DIR}/output)

# set(LIBRARY_OUTPUT_PATH ${LearnCPP_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

message(STATUS "this is binary dir " ${LearnCPP_BINARY_DIR})
message(STATUS "this is source dir " ${LearnCPP_SOURCE_DIR})

add_executable(main ${Bookstore})