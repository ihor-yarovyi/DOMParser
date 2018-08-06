cmake_minimum_required(VERSION 3.10)

project(InterfaceTests VERSION 1)

add_executable(InterfaceTests InterfaceTests.cpp)

target_link_libraries(InterfaceTests googletest ${LIBRARY_NAME})

install(TARGETS InterfaceTests
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
