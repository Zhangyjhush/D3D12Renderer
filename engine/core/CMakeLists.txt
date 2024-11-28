cmake_minimum_required(VERSION 3.18)

project(core)

# 查找源文件
file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")
file(GLOB_RECURSE CORE_HEADERS "include/*.h")

# 添加源文件组（保留目录结构）
foreach(_file IN LISTS CORE_SOURCES CORE_HEADERS)
    get_filename_component(_dir "${_file}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" _group "${_dir}")
    string(REPLACE "/" "\\" _group "${_group}")
    source_group("${_group}" FILES "${_file}")
endforeach()

# 添加库（动态）
add_executable( SobelApp WIN32  ${CORE_SOURCES} ${CORE_HEADERS})
if(MSVC)
    target_compile_definitions(SobelApp PRIVATE _UNICODE UNICODE)
endif()