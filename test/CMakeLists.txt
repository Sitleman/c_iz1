
#find_package(Threads REQUIRED)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test main.cpp test.cpp)

#target_link_libraries(test ${GTEST_LIBRARIES})
target_link_libraries(test GTest::GTest GTest::Main automobile input)
#add_test(NAME storage_tests COMMAND storage_tests)