cmake_minimum_required(VERSION 3.20)
project(library)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_SOURCES
    user.cc
    item.cc
    reader.cc
)

set(LIBRARY_HEADERS
    user.hh
    item.hh
    reader.hh
)

add_library(library SHARED ${LIBRARY_HEADERS} ${LIBRARY_SOURCES})
target_include_directories(library PUBLIC "./")
