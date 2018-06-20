cmake_minimum_required(VERSION 2.8)

project(DOMParser)

set(MAIN_SOURCE_FILES Teg.cpp Teg.h DOMParser.cpp DOMParser.h BaseParser.h AttributeParser.h AttributeParser.cpp AttributeValueParser.cpp AttributeValueParser.h ContentParser.cpp ContentParser.h TegNameParser.cpp TegNameParser.h)
add_executable(DOMParser main.cpp ${MAIN_SOURCE_FILES})