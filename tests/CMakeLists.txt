cmake_minimum_required(VERSION 3.10)

include(${CMAKE_SOURCE_DIR}/cmake/GoogleTest.cmake)

add_subdirectory(InterfaceTests)
add_subdirectory(ParserTest)
add_subdirectory(RulesParser)
add_subdirectory(WritePageDataTests)