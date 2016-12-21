cmake_minimum_required(VERSION 2.6)

set(SRCS main.cc)
IF (CMAKE_BUILD_TYPE MATCHES "Release")  
add_executable(client ${SRCS})
target_link_libraries(client
              flow_framework 
              )
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Debug")
add_executable(clientd ${SRCS})
target_link_libraries(clientd
              flow_framework 
              )
ENDIF()