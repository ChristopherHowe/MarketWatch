# version 3.15 or later of CMake needed for GoogleTest on Windows
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(marketwatch)

set(BUILD_SHARED_LIBS ON)

add_library(account src/account.cpp)
target_include_directories(account PUBLIC include)
add_library(libstructs src/libstructs.cpp)
target_include_directories(libstructs PUBLIC include)
add_library(market src/market.cpp)
target_include_directories(market PUBLIC include)
add_library(position src/position.cpp)
target_include_directories(position PUBLIC include)
add_library(stock src/stock.cpp)
target_include_directories(stock PUBLIC include)
add_library(timeSeriesDB src/timeSeriesDB.cpp)
target_include_directories(timeSeriesDB PUBLIC include)
add_library(user src/user.cpp)
target_include_directories(user PUBLIC include)

# PUBLIC needed to make .h and .cpp files accessible to exe
#Below was not working on its own for some reason, thats why all the target includes are
target_include_directories(marketwatch
    PUBLIC include/)


