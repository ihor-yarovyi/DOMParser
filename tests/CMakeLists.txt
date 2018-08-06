cmake_minimum_required(VERSION 2.8)

include(${CMAKE_SOURCE_DIR}/cmake/GoogleTest.cmake)

add_subdirectory(InterfaceTests)
add_subdirectory(ParserTest)
add_subdirectory(RulesParser)
add_subdirectory(WritePageDataTests)