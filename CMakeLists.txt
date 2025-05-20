cmake_minimum_required(VERSION 3.14)
project(RubberNumbers VERSION 1.0.0)

# General C++ standard config
# Note: GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default value for BUILD_TYPE variable
if(NOT BUILD_TYPE)
  set(BUILD_TYPE "release")
endif()

# Target specific config
if(BUILD_TYPE STREQUAL "testing")
  set(CMAKE_BUILD_TYPE "Debug")
  set(INCLUDE_TESTS TRUE)
elseif(BUILD_TYPE STREQUAL "release")
  set(CMAKE_BUILD_TYPE "Release")
  set(INCLUDE_TESTS FALSE)
elseif(BUILD_TYPE STREQUAL "coverage")
  set(INCLUDE_TESTS TRUE)
  # Start of codeblock based on Daniel Sieger's article at
  # https://danielsieger.com/blog/2022/03/06/code-coverage-for-cpp.html
  set(CMAKE_CXX_FLAGS "-O0 -coverage")
  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)

  # add coverage target
  add_custom_target(coverage
    COMMAND ${LCOV} --directory . --capture --output-file coverage.info
    COMMAND ${GENHTML} --demangle-cpp -o coverage coverage.info
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  # End of codeblock based on Daniel Sieger's article
elseif(BUILD_TYPE STREQUAL "profiling")
  set(CMAKE_CXX_FLAGS "-pg -O3")
  set(INCLUDE_TESTS TRUE)
else()
  message(FATAL_ERROR "No valid build type specified")
endif()

# Search GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
## For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Compile and link if necessary
if (INCLUDE_TESTS)
    # Based on GoogleTest quickstart guide: http://google.github.io/googletest/quickstart-cmake.html
    enable_testing()
    add_executable(rubber_numbers src/tests.cpp src/RubberNumbers/RubberIntegers.cpp)

    include(GoogleTest)
    gtest_discover_tests(rubber_numbers)

    target_link_libraries(
        rubber_numbers
        GTest::gtest_main
    )
else()
    add_library(rubber_numbers OBJECT src/RubberNumbers/RubberIntegers.cpp)
    set_property(TARGET rubber_numbers PROPERTY POSITION_INDEPENDENT_CODE TRUE)
    add_library(rubber_numbers_shared SHARED $<TARGET_OBJECTS:rubber_numbers>)
    add_library(rubber_numbers_static $<TARGET_OBJECTS:rubber_numbers>)
endif()

