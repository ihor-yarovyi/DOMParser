cmake_minimum_required(VERSION 3.10)

project(RulesParser VERSION 1)

add_executable(RulesParser RulesParser.cpp)

target_link_libraries(RulesParser googletest ${LIBRARY_NAME})

install(TARGETS RulesParser
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
