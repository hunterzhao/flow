cmake_minimum_required(VERSION 2.6)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -pthread -std=c++11 -Wall -O0")
include_directories(../include ../deps)
link_directories(../lib)

set(SOURCE_FILES  test.cc           
                  )

add_executable(test ${SOURCE_FILES})
target_link_libraries(test gtest_main flow_framework uv)
