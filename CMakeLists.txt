cmake_minimum_required(VERSION "3.1")

enable_testing()
include(GoogleTest)

add_library(lru STATIC ${CMAKE_CURRENT_SOURCE_DIR}/lru.cc)
target_include_directories(lru PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lru-test ${CMAKE_CURRENT_SOURCE_DIR}/lru-t.cc)
target_link_libraries(lru-test lru gtest gtest_main pthread)

gtest_discover_tests(lru-test)