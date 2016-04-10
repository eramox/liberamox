set (LIBRARY_NAME liberamox)

# set (ARDUINO_HEADER_HOME "${PROJECT_SOURCE_DIR}/../arduino_headers/")
set (ARDUINO_VARIANTS "standard")
if (CONTINUOUS_INTEGRATION_BUILD)
    set(ARDUINO_HEADER_HOME "${CMAKE_CURRENT_SOURCE_DIR}/../../arduino_headers")
endif (CONTINUOUS_INTEGRATION_BUILD)
find_package(Arduino PATHS "${CMAKE_CURRENT_SOURCE_DIR}") 

include_directories("${ARDUINO_PATH_HEADERS}")

# define specific...
add_definitions(-D__COMPILING_AVR_LIBC__)
add_definitions(-DF_CPU)
add_definitions(-D__OPTIMIZE__)
    # Avoid "warning: ‘__progmem__’ attribute directive ignored [-Wattributes]"
# add_definitions(-D__ATTR_PROGMEM__="   ")

# get sources
file(GLOB SOURCES_FILES . *.cpp)
file(GLOB HEADERS_FILES . *.h)
 
# add the executable
add_library(${LIBRARY_NAME} ${SOURCES_FILES})
SET_TARGET_PROPERTIES(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
