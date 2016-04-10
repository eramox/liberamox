# CMakeLists to build the library liberamox

set (LIBRARY_NAME liberamox)

if(ARDUINO_PLUGIN_HEADER_FOUND)
    include_directories (${ARDUINO_PLUGIN_PATH_HEADERS})
    add_definitions (${ARDUINO_PLUGIN_FLAG})
else()
    message(FATAL_ERROR " Cannot find headers for Arduino in ${ARDUINO_PLUGIN_HOME} for variant ${ARDUINO_PLUGIN_VARIANT}")
endif()

# get sources
file(GLOB SOURCES_FILES . *.cpp)
file(GLOB HEADERS_FILES . *.h)
 
# add the executable
add_library(${LIBRARY_NAME} ${SOURCES_FILES})
SET_TARGET_PROPERTIES(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
