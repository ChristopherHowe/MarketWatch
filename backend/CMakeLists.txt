# version 3.15 or later of CMake needed for GoogleTest on Windows
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(marketwatch)

set(BUILD_SHARED_LIBS ON)

add_library(account src/account.cpp)
add_library(libstructs src/libstructs.cpp)
add_library(market src/market.cpp)
add_library(position src/position.cpp)
add_library(stock src/stock.cpp)
add_library(timeSeriesDB src/timeSeriesDB.cpp)
add_library(user src/user.cpp)


# PUBLIC needed to make .h and .cpp files accessible to exe
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

