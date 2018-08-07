# DOMParser

This is a simple library for parsing DOM-document (html or xml).
You can build and use this library on Linux and Windows.

### How to compile?
## On Linux
Example of a local installation:

    > mkdir build
    > cd build
    > cmake -DCMAKE_INSTALL_PREFIX=../installed ..
    > make install
	
Uninstall library:

	> make uninstall
	
## On Windows (for example if you use Visual Studio)
Example of a local installation:

    > mkdir build
    > cd build
    > cmake -DCMAKE_INSTALL_PREFIX=../installed ..
	> Open the DOMParser.sln
	> Right-click on 'domparser' project
	> Choose 'properties'
	> 'Target Extension' set up .lib
	> 'Configuration Type' set up Static library (.lib)
	> Build solution
	> Choose 'INSTALL' project and build him

Uninstall library:	

	> Choose 'uninstall' project and build him

### How to use the library (internally)?

See the tests.

### How to use the library (in an external project)?

Once the library is installed, CMake will be able to find it using
`find_package()` command. For example:

    cmake_minimum_required(VERSION 3.10)
    project(SomeProject)

    find_package(DOMParser REQUIRED)
    include_directories(${DOMPARSER_INCLUDE_DIRS})

    add_executable(SomeProject SomeProject.cpp)
    target_link_libraries(SomeProject ${DOMPARSER_LIBRARIES})	