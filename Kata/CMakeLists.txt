add_library(Kata Kata.cpp)
add_executable(KataTest KataTest.cpp)
TARGET_LINK_LIBRARIES(KataTest Kata gtest pthread)
add_test(KataTest KataTest)