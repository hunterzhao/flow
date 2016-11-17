add_definitions(-DFLOW_FRAMEWORK_EXPORT)

set(SOURCE_FILES  
              flow_loop.cc
              flow_tcp_handle.cc
              flow_server.cc
              flow_client.cc
              )

if(TARGET flow_framework)

message("flow_framework is already defined")

else()

add_library(flow_framework STATIC ${SOURCE_FILES})
target_link_libraries(flow_framework uv)
add_library(flow_framework_so SHARED ${SOURCE_FILES})
set_target_properties(flow_framework_so PROPERTIES OUTPUT_NAME "flow_framework")
endif()