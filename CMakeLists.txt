# Specify minimum required version of cmake
cmake_minimum_required(VERSION 3.10)

# Specify project uses c++
project(se-05-team-19)

# To create the test executable in the main directory not in tests/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Let cmake know we will use unit tests
enable_testing()

include_directories(include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(socket)
add_subdirectory(docs)
add_subdirectory(tests)
