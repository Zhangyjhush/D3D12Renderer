cmake_minimum_required(VERSION 3.18)

project(dx_renderer)
set(CMAKE_CXX_STANDARD    14)
set(CMAKE_BUILD_TYPE "Debug")

include_directories(${CMAKE_SOURCE_DIR}/engine/core)
include_directories(${CMAKE_SOURCE_DIR}/engine/test)
include_directories(${CMAKE_SOURCE_DIR}/engine/win32)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/engine/core) 
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/engine/test) 
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/engine/win32) 

# include_directories(./include/)
# aux_source_directory(./src/ DIR_SRC)

# file(GLOB_RECURSE SOURCES "src/*.cpp")
# file(GLOB_RECURSE HEADERS "include/*.h")

# foreach(_file IN LISTS SOURCES HEADERS)
#     get_filename_component(_dir "${_file}" PATH)
#     string(REPLACE "${CMAKE_SOURCE_DIR}/" "" _group "${_dir}")
#     string(REPLACE "/" "\\" _group "${_group}")
#     source_group("${_group}" FILES "${_file}")
# endforeach()

# add_executable( SobelApp ${SOURCES} ${HEADERS})