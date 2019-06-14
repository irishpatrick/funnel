cmake_minimum_required(VERSION 3.0)

project(demo)

file(GLOB sources src/*)

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} PRIVATE funnel)