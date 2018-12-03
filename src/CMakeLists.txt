file(GLOB srcs
    "*.cpp"
    utils/*.cpp
)

file(GLOB test_srcs
    tests/*.cpp
)

add_library(AdventOfCode ${srcs})
add_executable(AdventOfCodeTest ${test_srcs})
TARGET_LINK_LIBRARIES(AdventOfCodeTest AdventOfCode gtest pthread)
add_test(AdventOfCodeTest AdventOfCodeTest)