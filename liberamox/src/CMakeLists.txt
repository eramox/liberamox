set (EXECUTABLE_NAME testlib)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "liberamoxconfig.h.in"
  "${PROJECT_BINARY_DIR}/src/liberamoxconfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")
 
# add the executable
add_executable(${EXECUTABLE_NAME} main.cpp)
SET_TARGET_PROPERTIES(${EXECUTABLE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
