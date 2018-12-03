add_library(AdventOfCode FileReader.cpp Day1.cpp Day2.cpp)
add_executable(AdventOfCodeTest Day1Test.cpp Day2Test.cpp)
TARGET_LINK_LIBRARIES(AdventOfCodeTest AdventOfCode gtest pthread)
add_test(AdventOfCodeTest AdventOfCodeTest)