# This file allow to set path to headers needed to build
# a library depending on arduino headers provided by ArduinoPlugin

# This file will check that the files needed are present:
# - Arduino.h
# - avr/pgmspace.h
# - pins_arduino.h (dependent on variant)
# It also set the C/CXX flags to set to avoid warning/errors when building

# Input:
# - ARDUINO_PLUGIN_VARIANT (The type of arduino used)
# - ARDUINO_PLUGIN_HOME (The path to arduinoPlugin folder)
#
# Output:
# - ARDUINO_PLUGIN_HEADER_FOUND if the headers are found
# - ARDUINO_PLUGIN_PATH_HEADERS the path to add to the compilation
# - ARDUINO_PLUGIN_FLAG the flags to add to the compilation


### ArduinoConfig ###
 #set(ARDUINOPLUGIN_VERSION 3.0) # We support the V3.0 of the ArduinoPlugin
 
### VARIABLE ###
 
 # default initialization of output variable
 set (ARDUINO_PLUGIN_HEADER_FOUND "-NOTFOUND")
 set (ARDUINO_PLUGIN_PATH_HEADERS "-NOTFOUND")
 set (ARDUINO_PLUGIN_FLAG         "")
 
 # Internal variable
 set (__PATH_ARDUINO_H   "-NOTFOUND")
 set (__PATH_ARDUINO_AVR "-NOTFOUND")
 set (__PATH_ARDUINO_PIN "-NOTFOUND")
 
 set (__HEADER_ARDUINO "-NOTFOUND")
 set (__HEADER_AVR     "-NOTFOUND")
 set (__HEADER_PINS    "-NOTFOUND")
 set (__HEADER_DEFINED OFF)
  
### EXECUTION ###
 # Search
 message (STATUS "Searching Arduino headers in: ${ARDUINO_PLUGIN_HOME}") 
 
 # It is supposed we know the structure of the folder, so we can
 # simply do a find path for the files
 
 #if("${PACKAGE_FIND_VERSION_MINOR}" EQUAL 3)
     # Path for ArduinoPlugin V3.0
     set (__HEADER_ARDUINO "packages/arduino/hardware/avr/1.6.10/cores/arduino/")
     set (__HEADER_AVR     "tools/arduino/avr-gcc/4.8.1-arduino5/avr/include/avr/")
     set (__HEADER_PINS    "packages/arduino/hardware/avr/1.6.10/variants/")
     set (__HEADER_DEFINED ON)
 #else ()
 #    message(ERROR " Please provide the version required")
 #endif("${PACKAGE_FIND_VERSION_MINOR}" EQUAL 3)
 
 function(searchArduinoHeader varPath header basePath extraPath)
     set (TEMP_PATH "${basePath}/${extraPath}")
     find_path (${varPath} ${header} ${TEMP_PATH})
     message (STATUS "Search ${header} in ${TEMP_PATH}")
     if (NOT ${varPath})
         message (SEND_ERROR "Cannot find ${header} in ${TEMP_PATH}")
     else ()
         message (STATUS "Found ${header}")
         set(${varPath} ${${varPath}} PARENT_SCOPE)
     endif ()    
 endfunction(searchArduinoHeader)
 
 if(__HEADER_DEFINED AND ARDUINO_PLUGIN_HOME AND ARDUINO_PLUGIN_VARIANT)
     # Find Arduino.h
     searchArduinoHeader (__PATH_ARDUINO_H "Arduino.h" 
            ${ARDUINO_PLUGIN_HOME} ${__HEADER_ARDUINO})
     # Find avr/pgmspace.h       
     searchArduinoHeader (__PATH_ARDUINO_AVR "pgmspace.h"
            ${ARDUINO_PLUGIN_HOME} ${__HEADER_AVR})
     # Find pins_arduino.h       
     searchArduinoHeader (__PATH_ARDUINO_PIN "pins_arduino.h"
            ${ARDUINO_PLUGIN_HOME} "${__HEADER_PINS}${ARDUINO_PLUGIN_VARIANT}")
     
     if(__PATH_ARDUINO_H AND __PATH_ARDUINO_AVR AND __PATH_ARDUINO_PIN)
         set (__ARDUINO_FOUND "true")
     else ()
         message(ERROR " Some headers couldn't be found:")
         message(STATUS "arduino: ${__PATH_ARDUINO_H}")
         message(STATUS "AVR: ${__PATH_ARDUINO_AVR}")
         message(STATUS "pin: ${__PATH_ARDUINO_PIN}")
     endif()
 else()
     if(NOT __HEADER_DEFINED)
         message(ERROR " Intermediate path to header not defined")
     endif()
     if(NOT ARDUINO_PLUGIN_HOME)
         message(ERROR " Home not defined")
     endif()
     if(NOT ARDUINO_PLUGIN_VARIANT)
         message(ERROR " Variant not defined")
     endif()
 endif(__HEADER_DEFINED AND ARDUINO_PLUGIN_HOME AND ARDUINO_PLUGIN_VARIANT)
 
 ### OUTPUT ###
 
  # Setting output variable
  set (ARDUINO_PLUGIN_HEADER_FOUND ${__ARDUINO_FOUND})
  set (__PATH_ARDUINO_AVR "${__PATH_ARDUINO_AVR}/..")
  set (ARDUINO_PLUGIN_PATH_HEADERS  
         "${__PATH_ARDUINO_H};${__PATH_ARDUINO_AVR};${__PATH_ARDUINO_PIN}")
  set (ARDUINO_PLUGIN_FLAG "-D__COMPILING_AVR_LIBC__ -DF_CPU -D__OPTIMIZE__ -D__ATTR_PROGMEM__=\" \"")  
         
 
  mark_as_advanced(
     ARDUINO_PLUGIN_HEADER_FOUND
     ARDUINO_PLUGIN_PATH_HEADERS
     ARDUINO_PLUGIN_FLAG)
     
     
