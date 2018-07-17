cmake_minimum_required(VERSION 2.8)

project(ParserTest)

include(${CMAKE_SOURCE_DIR}/cmake/GoogleTest.cmake)

add_executable(ParserTest ParserTest.cpp)

target_link_libraries(ParserTest googletest ${LIBRARY_NAME})

install(TARGETS ParserTest
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
