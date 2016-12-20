cmake_minimum_required(VERSION 3.6)
project(midiparser_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")




set(SOURCE_FILES
        src/midiparser.h
        src/events.cpp
        src/events.h
        src/components.cpp
        src/components.h
        src/operator_overrides.cpp
        src/operator_overrides.h src/parsing.cpp src/parsing.h src/parser.cpp src/parser.h)
ADD_LIBRARY(midiparser STATIC ${SOURCE_FILES})