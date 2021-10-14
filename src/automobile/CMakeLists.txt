add_library(automobile automobile.h automobile.c)

target_include_directories(automobile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})