cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(${CMAKE_CURRENT_SOURCE_DIR}/csm_fixture/CMakeLists.txt)

set(COVERAGE OFF CACHE BOOL "Coverage")

# Link runSensorUtilsTests with what we want to test and the GTest and pthread library

add_executable(runSensorUtilsTests TestMain.cpp
                                   SensorCoreTesting.cpp
                                   SensorMathTesting.cpp
                                   SensorModelTesting.cpp
                                   ShapeModelTesting.cpp)

target_link_libraries(runSensorUtilsTests PUBLIC
                      sensorutils
                      ${GMOCK_LIBRARY}
                      pthread
                      fixturecsm)

include_directories(${SENSORUTILS_PRIVATE_INCLUDE_DIRS}
                    ${SENSORUTILS_PUBLIC_INCLUDE_DIRS}
                    ${ARMADILLO_INCLUDE_DIR})

if(COVERAGE)
    target_link_libraries(runSensorUtilsTests PRIVATE --coverage)
endif()

gtest_discover_tests(runSensorUtilsTests WORKING_DIRECTORY tests)
