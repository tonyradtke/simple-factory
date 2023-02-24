cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # not necessary, but encouraged

project(demo)

#
# set vars
#
SET(LIB_NAME "simple-factory")

#
#  wrangle files
#
include_directories("include/")

#
# link
#
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE .)

#
# install
#
install(TARGETS ${LIB_NAME} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/
        FILES_MATCHING PATTERN "*.hh")


