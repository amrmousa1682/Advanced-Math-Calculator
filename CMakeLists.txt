cmake_minimum_required(VERSION 3.24)  # CMake version check
project(Advanced-Math-Calculator)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp convert.cpp convert.h helpers.cpp helpers.h menus.cpp menus.h solvers.cpp solvers.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(Advanced-Math-Calculator ${SOURCE_FILES})
