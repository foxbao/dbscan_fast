project( DBSCAN )
cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )
set(CMAKE_BUILD_TYPE "Release")

ADD_SUBDIRECTORY(lib bin)
INCLUDE_DIRECTORIES(lib/include)
set(SOURCES main.cpp)

add_executable(dbscan_example ${SOURCES})
TARGET_LINK_LIBRARIES(dbscan_example dbscan test)