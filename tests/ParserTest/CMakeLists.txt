cmake_minimum_required(VERSION 3.10)

project(ParserTest VERSION 1)

add_executable(ParserTest ParserTest.cpp)

target_link_libraries(ParserTest googletest ${LIBRARY_NAME})

install(TARGETS ParserTest
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
