
PROJECT(feature)

set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.0)

add_definitions("-g")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} regex.cpp)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT
						 ${PROJECT_NAME})
