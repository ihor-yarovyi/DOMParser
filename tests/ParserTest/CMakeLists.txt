cmake_minimum_required(VERSION 2.8)

project(ParserTest)

include_directories(../../src)

set(GTEST_SRC ../../googletest/googletest/src/gtest-all.cc)
include_directories(../../googletest/googletest ../../googletest/googletest/include)

find_package(Threads)
add_library(googletest STATIC ${GTEST_SRC})
target_link_libraries(googletest ${CMAKE_THREAD_LIBS_INIT})

add_executable(ParserTest ./ParserTest.cpp
  ../../src/TegNameParser.cpp)
target_link_libraries(ParserTest googletest)