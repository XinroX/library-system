cmake_minimum_required(VERSION 3.20)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_SOURCES
    user.cc
    item.cc
)

set(LIBRARY_HEADERS
    user.hh
    item.hh
)

add_library(LIBRARY SHARED ${LIBRARY_HEADERS} ${LIBRARY_SOURCES})
target_include_directories(LIBRARY PUBLIC "./")
