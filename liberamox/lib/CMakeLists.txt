set (LIBRARY_NAME liberamox)

# Arduino plugin for eclipse
set (ARDUINO_HOME "/opt/eclipse/arduinoPlugin")
# Arduino
set(ARDUINO_INCLUDE_DIR "${ARDUINO_HOME}/packages/arduino/hardware/avr/1.6.10/cores/arduino")
# AVR includes
set(AVR_INCLUDE_DIR "${ARDUINO_HOME}/tools/arduino/avr-gcc/4.8.1-arduino5/avr/include/")
# Pin configuration depending on board !!
set (PIN_CONFIG_INCLUDE "${ARDUINO_HOME}/packages/arduino/hardware/avr/1.6.10/variants/standard/")

include_directories("${ARDUINO_INCLUDE_DIR};${AVR_INCLUDE_DIR};${PIN_CONFIG_INCLUDE}")

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
