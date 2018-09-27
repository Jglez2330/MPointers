cmake_minimum_required(VERSION 3.12)
project(MPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MPointers main.cpp Socket.cpp Socket.h ServerMemoryManagement.cpp ServerMemoryManagement.h LinkedList.cpp LinkedList.h Node.cpp Node.h MPointer.h MPointer.cpp)