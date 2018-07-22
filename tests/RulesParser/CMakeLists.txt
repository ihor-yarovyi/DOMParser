cmake_minimum_required(VERSION 2.8)

project(RulesParser)

add_executable(RulesParser RulesParser.cpp)

target_link_libraries(RulesParser googletest ${LIBRARY_NAME})

install(TARGETS RulesParser
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
