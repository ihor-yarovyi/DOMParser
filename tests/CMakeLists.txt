cmake_minimum_required(VERSION 2.8)

project(DOMParserTests)

find_package(Threads REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../src)

add_executable(DOMParserTests DOMParserTests.cpp)

target_link_libraries(DOMParserTests gtest gtest_main Threads::Threads)
