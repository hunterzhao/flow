cmake_minimum_required(VERSION 2.6)

set(SRCS main.cc)
add_executable(client ${SRCS})
target_link_libraries(client
              flow_framework 
              )