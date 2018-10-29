# Include python
include(FindPythonAnaconda.cmake)
include_directories(${PYTHON_INCLUDE_DIR})

set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR sensors)
set_source_files_properties(../SensorUtils.i
                            PROPERTIES CPLUSPLUS ON)

include_directories(${SENSORUTILS_PUBLIC_INCLUDE_DIRS})

# Add and link
swig_add_library(sensors
                 LANGUAGE python
                 SOURCES ../SensorUtils.i)
set_target_properties(_sensors PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SWIG_OUTDIR})
add_dependencies(_sensors sensorutils)

swig_link_libraries(sensors sensorutils ${PYTHON_LIBRARY})

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
