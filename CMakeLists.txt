cmake_minimum_required(VERSION 2.8)

project(DOMParser)
set(CMAKE_CXX_STANDARD 14)

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
add_subdirectory(${LIBRARY_FOLDER})
add_subdirectory(tests)

# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)
