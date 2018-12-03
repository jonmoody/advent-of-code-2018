file(GLOB srcs
    "*.cpp"
    utils/*.cpp
)

add_library(AdventOfCode ${srcs})
add_executable(AdventOfCodeTest Day1Test.cpp Day2Test.cpp)
TARGET_LINK_LIBRARIES(AdventOfCodeTest AdventOfCode gtest pthread)
add_test(AdventOfCodeTest AdventOfCodeTest)