cmake_minimum_required (VERSION 2.6)
project (AdventOfCodeMain)

ENABLE_TESTING()

# The version number.
set (ADVENT_OF_CODE_VERSION_MAJOR 1)
set (ADVENT_OF_CODE_VERSION_MINOR 0)

# Greetings
include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_BINARY_DIR}/ci"
  "${PROJECT_BINARY_DIR}/src"
)
add_subdirectory(ci)
add_subdirectory(src)

configure_file (
  "${PROJECT_SOURCE_DIR}/AdventOfCodeConfig.h.in"
  "${PROJECT_BINARY_DIR}/AdventOfCodeConfig.h"
)

add_executable(AdventOfCodeMain AdventOfCode.cpp)
target_link_libraries (AdventOfCodeMain AdventOfCode)
