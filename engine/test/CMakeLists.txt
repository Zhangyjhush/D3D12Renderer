cmake_minimum_required(VERSION 3.18)

project(test)

# 查找源文件
file(GLOB_RECURSE Test_SOURCES "src/*.cpp")
file(GLOB_RECURSE Test_HEADERS "include/*.h")

# 添加源文件组（保留目录结构）
foreach(_file IN LISTS Test_SOURCES Test_HEADERS)
    get_filename_component(_dir "${_file}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" _group "${_dir}")
    string(REPLACE "/" "\\" _group "${_group}")
    source_group("${_group}" FILES "${_file}")
endforeach()

# 添加库（动态）
add_executable(main ${Test_SOURCES} ${Test_HEADERS})

target_link_libraries(main PUBLIC core)

target_include_directories(main PUBLIC core/include)
# add_library(test SHARED ${Test_SOURCES} ${Test_HEADERS})
if(MSVC)
    target_compile_definitions(main PRIVATE _UNICODE UNICODE)
endif()