cmake_minimum_required(VERSION 2.6)

set(SRCS main.cc)
IF (CMAKE_BUILD_TYPE MATCHES "Release")  
add_executable(server ${SRCS})
target_link_libraries(server
              flow_framework 
              )
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Debug")
add_executable(serverd ${SRCS})
target_link_libraries(serverd
              flow_framework 
              )
ENDIF()