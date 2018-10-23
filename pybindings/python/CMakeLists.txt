# Include python
include(FindPythonAnaconda.cmake)
include_directories(${PYTHON_INCLUDE_DIR})

set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR sensors)
set_source_files_properties(../sensorutils.i
                            PROPERTIES CPLUSPLUS ON)

#Find dependencies
find_path(SENSORUTILS_INCLUDE_DIR NAMES SensorModelFactory.h
                                   PATH_SUFFIXES sensorutils
                                   PATHS ${PYTHON_INCLUDE_DIR}/../)
find_library(SENSORUTILS_LIBRARY NAMES sensorutils
            PATHS ${PYTHON_LIBRARY}/../)

message(STATUS "Found SensorUtils Include: ${SENSORUTILS_INCLUDE_DIR}")
message(STATUS "Found SensorUtils Lib: ${SENSORUTILS_LIBRARY}")

include_directories(${SENSORUTILS_INCLUDE_DIR})

# Add and link
swig_add_library(sensors
                 LANGUAGE python
                 SOURCES ../sensorutils.i)
set_target_properties(_sensors PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SWIG_OUTDIR})
swig_link_libraries(sensors ${SENSORUTILS_LIBRARY} ${PYTHON_LIBRARY})

# Build out a standard directory structure
# file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)

# Move the static files to move
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in
               ${CMAKE_CURRENT_BINARY_DIR}/setup.py
               COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py
               ${CMAKE_CURRENT_BINARY_DIR}/sensors/__init__.py
               COPYONLY)

# Move the tests
# file(COPY ${CMAKE_SOURCE_DIR}/python/tests
     # DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
