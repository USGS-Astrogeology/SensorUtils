cmake_minimum_required(VERSION 3.10)
project(sensorutils VERSION 0.1.1 DESCRIPTION "SensorUtils library")

include(cmake/gtest.cmake)
include(GNUInstallDirs)
include(GoogleTest)

set(CMAKE_CXX_STANDARD 11)

set(COVERAGE OFF CACHE BOOL "Coverage")


#add_subdirectory(CSM-CameraModel)
set(CAMERA_MODEL_INCLUDE_DIR,../CSM-CameraModel/include/usgscsm/)
set(CAMERA_MODEL_LIB_DIR,../CSM-CameraModel/)
set(CSMAPI_INCLUDE_DIR,../CSM-CameraModel/csm/include/csm/)
set(CSMAPI_LIB_DIR,../CSM-CameraModel/csm/)


find_library(CAMERA_MODEL_LIBRARY usgscsm PATHS ../CSM-CameraModel/)
find_library(CSMAPI_LIBRARY csmapi PATH ../csm/)



message(${CMAKE_DL_LIBS})


add_library(sensorutils SHARED
            src/SensorUtils.cpp
            src/sensorcore/Sensor.cpp
            src/sensormath/SensorMath.cpp
	          src/shapemodel/ShapeModel.cpp
            src/sensormodel/SensorModelFactory.cpp)

if(COVERAGE)
    target_compile_options(sensorutils PRIVATE --coverage -O0)
    target_link_libraries(sensorutils PRIVATE --coverage -O0)
endif()



set_target_properties(sensorutils PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

find_package(Threads)

# This is the linear algebra library we are using
find_package(Armadillo REQUIRED)

target_include_directories(sensorutils
                           PUBLIC
                           ../CSM-CameraModel/csm/include/csm/
                           ../CSM-CameraModel/csm/include/
                           ../CSM-CameraModel/include/usgscsm/
                           ../CSM-CameraModel/include/
                           include/sensorutils/
                           include/sensorcore/
                           include/sensormath/
                           include/sensormodel/
                           include/shapemodel/
                           include/
                           ${ARMADILLO_INCLUDE_DIRS}
)

message(${ARMADILLO_LIBRARIES})

target_link_libraries(sensorutils PUBLIC
                      gtest ${CMAKE_THREAD_LIBS_INIT}
                      ${ARMADILLO_LIBRARIES} ${CAMERA_MODEL_LIBRARY}
                       ${CSMAPI_LIBRARY} ${CMAKE_DL_LIBS})

install(TARGETS sensorutils
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sensorutils)



option (BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()
