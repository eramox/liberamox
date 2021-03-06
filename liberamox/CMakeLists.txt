#
# File generated by CMakeBuilder
#
#
cmake_minimum_required (VERSION 2.6)

set (PROJECTNAME "liberamox")
project ( ${PROJECTNAME} CXX )

message (STATUS "Building ${PROJECTNAME} using CMake ${CMAKE_VERSION}")

option(CONTINUOUS_INTEGRATION_BUILD "Build the static library" OFF)
option(BUILD_LIB_TEST "Build tests" OFF)

# The version number.
set (LIBERAMOX_VERSION_MAJOR 2)
set (LIBERAMOX_VERSION_MINOR 1)
set (LIBERAMOX_PATCH_MINOR   45)

if (CONTINUOUS_INTEGRATION_BUILD)
    message(STATUS "Starting Integration build")
endif ()

set (CMAKE_DEBUG_VALUE true)

# We search for ArduinoPlugin configuration
# We need to set 
if (CONTINUOUS_INTEGRATION_BUILD)
    set(ARDUINO_PLUGIN_HOME "${CMAKE_CURRENT_SOURCE_DIR}/../arduino_headers/arduinoPlugin")
endif()

set (ARDUINO_PLUGIN_VARIANT "standard")
find_package(ArduinoPlugin PATHS "${CMAKE_CURRENT_SOURCE_DIR}/cmake") 

if(NOT ArduinoPlugin_FOUND)
    message(FATAL_ERROR " Cannot find headers for Arduino in ${ARDUINO_PLUGIN_HOME} for variant ${ARDUINO_PLUGIN_VARIANT}")
endif()

message (STATUS "Configuring the project ${PROJECT_NAME}") 

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(testing)
