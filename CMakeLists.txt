 # version 3.15 or later of CMake needed for GoogleTest on Windows
# so let's require it now.
cmake_minimum_required(VERSION 3.15)

project(
    marketwatch
    VERSION 0.1
    DESCRIPTION "stock data process")

add_subdirectory(app)  
add_subdirectory(backend) 

#add_subdirectory(apps)    
#if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
#add_subdirectory(tests)
#endif() #PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME