cmake_minimum_required(VERSION 3.16)
project(c_iz1 C CXX)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)

add_executable(main main.c)
target_link_libraries(main PUBLIC menu)

add_subdirectory(test)