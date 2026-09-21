cmake_minimum_required(VERSION 3.14)
project(lab4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Покрытие
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")

include_directories(include)

add_library(structures STATIC
    src/Stack.cpp
    src/Queue.cpp
    src/BinaryTree.cpp
)

add_executable(app src/main.cpp)
target_link_libraries(app structures)

# Google Test
find_package(GTest REQUIRED)
enable_testing()

add_executable(tests tests/test_structures.cpp)
target_link_libraries(tests structures GTest::gtest GTest::gtest_main pthread)

add_test(NAME all_tests COMMAND tests)