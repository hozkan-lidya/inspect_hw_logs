cmake_minimum_required(VERSION 3.10)

project(markets_tests)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)



SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
    )


file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cc"
        "${PROJECT_SOURCE_DIR}/app/*.cc"
        )

add_executable(run_tests ${all_SRCS} )