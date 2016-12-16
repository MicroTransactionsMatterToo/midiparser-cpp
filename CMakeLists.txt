cmake_minimum_required(VERSION 3.6)
project(midiparser_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/events.cpp src/events.h src/midiparser.h)
add_executable(midiparser_c ${SOURCE_FILES})