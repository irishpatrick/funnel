cmake_minimum_required(VERSION 3.0)

project(funnel)

file(GLOB sources src/*)

add_library(${PROJECT_NAME} STATIC ${sources})

add_subdirectory(./demo)
