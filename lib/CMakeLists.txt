project(dbscan)
cmake_minimum_required(VERSION 3.5)
SET(LIBDBSCAN_SRC dbscan.cpp)
MESSAGE(STATUS "This is CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
ADD_LIBRARY(dbscan SHARED ${LIBDBSCAN_SRC})
SET_TARGET_PROPERTIES(dbscan PROPERTIES VERSION 1.2 SOVERSION 1)
SET_TARGET_PROPERTIES(dbscan PROPERTIES OUTPUT_NAME "dbscan")
SET_TARGET_PROPERTIES(dbscan PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(LIBTEST test.cpp)

ADD_LIBRARY(test SHARED ${LIBTEST})
SET_TARGET_PROPERTIES(test PROPERTIES VERSION 1.2 SOVERSION 1)
SET_TARGET_PROPERTIES(test PROPERTIES OUTPUT_NAME "test")
SET_TARGET_PROPERTIES(test PROPERTIES CLEAN_DIRECT_OUTPUT 1)