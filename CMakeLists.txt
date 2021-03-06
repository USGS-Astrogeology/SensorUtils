cmake_minimum_required(VERSION 3.10)
project(sensorutils VERSION 0.1.1 DESCRIPTION "SensorUtils library")

include(cmake/gtest.cmake)
include(GNUInstallDirs)
include(GoogleTest)

set(CMAKE_CXX_STANDARD 11)

set(COVERAGE OFF CACHE BOOL "Coverage")

# Third party dependencies
find_package(Threads)
find_package(Armadillo REQUIRED PATHS $ENV{CONDA_PREFIX})

# Optional build or link against CSM
option (BUILD_CSM "Build the CSM library" ON)
if(BUILD_CSM)
  add_subdirectory(csm)
  set(CSM_INCLUDE_DIR /csm)
  set(CSM_LIBRARY csmapi)
else()
  find_path(CSM_INCLUDE_DIR NAMES "csm.h"
			    PATH_SUFFIXES "csm"
			    PATHS $ENV{CONDA_PREFIX}/include/)
  find_library(CSM_LIBRARY csmapi PATHS $ENV{CONDA_PREFIX}/lib)

  message("--Found CSM Library: ${CSM_LIBRARY}")
  message("--Found CSM Include Directory: ${CSM_INCLUDE_DIR}")
endif(BUILD_CSM)

add_library(sensorutils SHARED
            src/sensorcore/Sensor.cpp
            src/sensormath/SensorMath.cpp
            src/shapemodel/BiAxialEllipsoid.cpp
            src/shapemodel/ShapeModel.cpp
            src/shapemodel/ShapeModelFactory.cpp
	          src/sensormodel/CSMSensorModel.cpp
	          src/sensormodel/SensorModelFactory.cpp)


if(COVERAGE)
    target_compile_options(sensorutils PRIVATE --coverage -O0)
    target_link_libraries(sensorutils PRIVATE --coverage -O0)
endif()

set_target_properties(sensorutils PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

set(SENSORUTILS_PUBLIC_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/api/")
set(SENSORUTILS_PRIVATE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(sensorutils
                           PUBLIC
                           ${SENSORUTILS_PUBLIC_INCLUDE_DIRS}
                           PRIVATE
                           ${SENSORUTILS_PRIVATE_INCLUDE_DIRS}
                           ${ARMADILLO_INCLUDE_DIRS}
                           ${CSM_INCLUDE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/include/json)


target_link_libraries(sensorutils PUBLIC
                      gtest ${CMAKE_THREAD_LIBS_INIT}
                      ${ARMADILLO_LIBRARIES}
                      ${CSM_LIBRARY})

set(PYBINDINGS ON CACHE BOOL "Turn on Python Bindings")
if(PYBINDINGS)
  include(${CMAKE_CURRENT_SOURCE_DIR}/pybindings/CMakeLists.txt)
endif()

install(TARGETS sensorutils
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${SENSORUTILS_PUBLIC_INCLUDE_DIRS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sensorutils)


option (BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()
