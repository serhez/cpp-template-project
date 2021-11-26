# Set CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(example)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Set key directories
set(SOURCE ${CMAKE_SOURCE_DIR}/src)
set(TESTS ${CMAKE_SOURCE_DIR}/tests)

# Set build/bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the source files
set(SOURCE_FILES ${SOURCE}/template.cpp)
set(TESTS_SOURCE_FILES ${TESTS}/test_template.cpp)

# Add the app's executable
add_executable(example ${SOURCE}/main.cpp ${SOURCE_FILES})
target_include_directories(example PRIVATE ${SOURCE})

# Add the tests' executable
add_executable(tests ${TESTS}/test_main.cpp ${SOURCE_FILES} ${TESTS_SOURCE_FILES})
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(url https://github.com/philsquared/Catch/releases/download/v2.13.6/catch.hpp)
file(
  DOWNLOAD ${url} "${CMAKE_CURRENT_BINARY_DIR}/catch.hpp"
  STATUS status
  EXPECTED_HASH SHA256=681e7505a50887c9085539e5135794fc8f66d8e5de28eadf13a30978627b0f47)
list(GET status 0 error)
if(error)
  message(FATAL_ERROR "Could not download ${url}")
endif()
target_include_directories(tests PUBLIC ${SOURCE} ${CMAKE_CURRENT_BINARY_DIR})
