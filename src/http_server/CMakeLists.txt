find_package(cpprestsdk REQUIRED)
add_library(httpserver SHARED server.cpp)
target_link_libraries(httpserver PUBLIC cpprestsdk::cpprest)
# target_include_directories(httpserver PUBLIC "./")
