cmake_minimum_required(VERSION 2.6)

set(SRCS main.cc)
add_executable(server ${SRCS})
target_link_libraries(server
              flow_framework
              )