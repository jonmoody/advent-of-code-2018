cmake_minimum_required (VERSION 2.6)
project (KataMain)

ENABLE_TESTING()

# The version number.
set (KATA_VERSION_MAJOR 1)
set (KATA_VERSION_MINOR 0)

# Greetings
include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_BINARY_DIR}/ci"
  "${PROJECT_BINARY_DIR}/Kata"
)
add_subdirectory(ci)
add_subdirectory(Kata)

configure_file (
  "${PROJECT_SOURCE_DIR}/KataConfig.h.in"
  "${PROJECT_BINARY_DIR}/KataConfig.h"
)

add_executable(KataMain Kata.cpp)
target_link_libraries (KataMain Kata)
