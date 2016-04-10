 # ArduinoConfig
 
 set (__PATH_ARDUINO_H)
 set (__PATH_ARDUINO_AVR)
 set (__PATH_ARDUINO_PIN)
 
 # default initialozation
 set(ARDUINO_FOUND "false")
 set(ARDUINO_PATH_HEADERS " ")
 
 set (ARDUINO_VARIANTS "standard")
  
 # Search
 message (STATUS "Searching Arduino headers in: ${ARDUINO_HEADER_HOME}") 
 
 # Find Arduino.h
 file(GLOB_RECURSE __PATH_ARDUINO_H_FILE "${ARDUINO_HEADER_HOME}/*Arduino.h")
 message (STATUS "__PATH_ARDUINO_H_FILE: ${__PATH_ARDUINO_H_FILE}") 
 get_filename_component(__PATH_ARDUINO_H ${__PATH_ARDUINO_H_FILE} DIRECTORY)
 message (STATUS "__PATH_ARDUINO_H: ${__PATH_ARDUINO_H}") 
 
 # Find avr/pgmspace.h
 file(GLOB_RECURSE __PATH_ARDUINO_AVR_FILE 
     "${ARDUINO_HEADER_HOME}/*pgmspace.h")
 message (STATUS "__PATH_ARDUINO_AVR_FILE: ${__PATH_ARDUINO_AVR_FILE}") 
 get_filename_component(__PATH_ARDUINO_AVR ${__PATH_ARDUINO_AVR_FILE} DIRECTORY)
 set(__PATH_ARDUINO_AVR "${__PATH_ARDUINO_AVR}/../")
 message (STATUS "__PATH_ARDUINO_AVR: ${__PATH_ARDUINO_AVR}") 
 
  # Find pins_arduino.h
 file(GLOB_RECURSE     __PATH_ARDUINO_ALL_PIN_FILE 
     "${ARDUINO_HEADER_HOME}/*pins_arduino.h")
 foreach(pin_header ${__PATH_ARDUINO_ALL_PIN_FILE})
     set(POS_FOLDER -1)
     string(FIND ${pin_header} ${ARDUINO_VARIANTS} POS_FOLDER)
     if(NOT ${POS_FOLDER} VERSION_EQUAL -1)
         set(__PATH_ARDUINO_PIN_FILE ${pin_header})
     endif(NOT ${POS_FOLDER} VERSION_EQUAL -1) 
 ENDFOREACH(pin_header)
 message (STATUS "__PATH_ARDUINO_PIN_FILE: ${__PATH_ARDUINO_PIN_FILE}") 
 get_filename_component(__PATH_ARDUINO_PIN ${__PATH_ARDUINO_PIN_FILE} DIRECTORY)
 message (STATUS "__PATH_ARDUINO_PIN: ${__PATH_ARDUINO_PIN}") 
 
 set (__ARDUINO_FOUND "True")
 
 # Setting output variable
 set (ARDUINO_FOUND ${__ARDUINO_FOUND})
 set (ARDUINO_PATH_HEADERS  
         "${__PATH_ARDUINO_H};${__PATH_ARDUINO_AVR};${__PATH_ARDUINO_PIN}")
 
 mark_as_advanced(
  ARDUINO_FOUND
  ARDUINO_PATH_HEADERS)