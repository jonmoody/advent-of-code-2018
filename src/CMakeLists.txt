add_library(AdventOfCode Day1.cpp)
add_executable(Day1Test Day1Test.cpp)
TARGET_LINK_LIBRARIES(Day1Test AdventOfCode gtest pthread)
add_test(Day1Test Day1Test)