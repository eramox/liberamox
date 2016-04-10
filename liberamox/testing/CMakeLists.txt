set (EXECUTABLE_NAME completetestlib)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")

# add the sources to the include directive
include_directories("../lib")

find_package(GTest REQUIRED)
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

if (BUILD_LIB_TEST)
    include( CTest )
endif()

# add the executable
add_executable(${EXECUTABLE_NAME} main.cpp)
SET_TARGET_PROPERTIES(${EXECUTABLE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${EXECUTABLE_NAME} ${GTEST_BOTH_LIBRARIES})

# Test
if (BUILD_LIB_TEST)
    add_test(liberamox_test ${EXECUTABLE_NAME})
endif()
