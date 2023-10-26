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