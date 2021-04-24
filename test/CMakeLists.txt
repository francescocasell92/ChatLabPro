add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES UserTest.cpp)
add_executable( RunAllTest.cpp ${TEST_SOURCE_FILES})
target_link_libraries(RunAllTest.cpp gtest gtest_main core)