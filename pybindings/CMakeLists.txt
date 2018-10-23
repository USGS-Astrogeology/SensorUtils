cmake_minimum_required(VERSION 3.10)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/python)
# add_subdirectory(fixture)
