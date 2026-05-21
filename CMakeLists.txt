cmake_minimum_required(VERSION 3.10)
project(SerialParser VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(serial_parser src/main.cpp src/SerialParser.cpp)
