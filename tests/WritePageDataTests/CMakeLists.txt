cmake_minimum_required(VERSION 2.8)

project(WritePageDataTests)

add_executable(WritePageDataTests WritePageDataTests.cpp)

target_link_libraries(WritePageDataTests googletest ${LIBRARY_NAME})

install(TARGETS WritePageDataTests
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)