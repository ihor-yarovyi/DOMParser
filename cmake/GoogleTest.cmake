set(GTEST_SRC ${CMAKE_SOURCE_DIR}/googletest/googletest/src/gtest-all.cc)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest 
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include)
    
find_package(Threads)
add_library(googletest STATIC ${GTEST_SRC})
target_link_libraries(googletest ${CMAKE_THREAD_LIBS_INIT})
