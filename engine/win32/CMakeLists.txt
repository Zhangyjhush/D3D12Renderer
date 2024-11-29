cmake_minimum_required(VERSION 3.18)

file(GLOB_RECURSE CORE_SOURCES "*.cpp")

project(SobelApp)

# 添加库（动态）
# add_library(core SHARED *.cpp)
add_executable( SobelApp WIN32 ${CORE_SOURCES})
target_link_libraries(SobelApp PUBLIC core)
target_include_directories(SobelApp PUBLIC core/include)
if(MSVC) 
    target_compile_definitions(SobelApp PRIVATE _UNICODE UNICODE)
endif()