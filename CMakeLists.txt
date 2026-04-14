cmake_minimum_required(VERSION 3.16)

# Project Name Version & main Languages.
project(unit-9 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    plog
    GIT_REPOSITORY https://github.com/SergiusTheBest/plog
    GIT_TAG        1.1.10
    GIT_SHALLOW    true
)
FetchContent_MakeAvailable(plog) # Downloads and adds plog to your CMake project

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

add_subdirectory(core)
add_subdirectory(client)
add_subdirectory(server)