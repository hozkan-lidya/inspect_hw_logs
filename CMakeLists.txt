cmake_minimum_required(VERSION 3.10)

project(markets_tests)

set(CMAKE_CXX_STANDARD)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-std=c++17  -Wall -Wextra -fPIC -Iinclude")  #-lstdc++fs
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB all_SRCS "${PROJECT_SOURCE_DIR}/src/*.cc")

# add_executable(run_tests ${all_SRCS} )
# CMake instructions to make the static lib
ADD_LIBRARY( mdlogs STATIC ${all_SRCS} )

# CMake instructions to test using the static lib
SET( APP_EXE run)
ADD_EXECUTABLE( ${APP_EXE} "${PROJECT_SOURCE_DIR}/app/main.cc" )
TARGET_LINK_LIBRARIES( ${APP_EXE} mdlogs )