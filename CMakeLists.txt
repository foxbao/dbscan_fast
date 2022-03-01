project( DBSCAN )
cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )
set(CMAKE_BUILD_TYPE "Release")

set(SOURCES main.cpp dbscan.cpp nanoflann.hpp)

add_executable(dbscan_example ${SOURCES})