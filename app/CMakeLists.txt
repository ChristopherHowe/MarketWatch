# version 3.15 or later of CMake needed for GoogleTest on Windows
cmake_minimum_required(VERSION 3.15)

project(marketwatch)
include_directories(GLOB SOURCES "../backend/include/")
file(GLOB SOURCES "../backend/src/*.cpp")



add_executable(marketwatch ${SOURCES} driver.cpp)

find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
#include_directories("/usr/local/lib")
target_include_directories(marketwatch PUBLIC "/usr/local/lib")
target_link_libraries(marketwatch ${CURL_LIBRARIES} restbed)



message("finished including restbed")