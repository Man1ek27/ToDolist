cmake_minimum_required(VERSION 3.10)

project(TO_DO_LIST)

add_definitions(-DPROJECTPATH=\"${PROJECT_SOURCE_DIR}\")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp &{SOURCES})


