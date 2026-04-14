cmake_minimum_required(VERSION 3.16)

# Project Name Version & main Languages.
project(core2 VERSION 1.0.0 LANGUAGES CXX)

add_library(core SHARED  
    core.cpp
)

target_include_directories(core2
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/private
)

