cmake_minimum_required(VERSION 3.16)

# Project Name Version & main Languages.
project(client VERSION 1.0.0 LANGUAGES CXX)

# Find Boost
find_package(Boost REQUIRED COMPONENTS program_options)
set(CMAKE_CXX_STANDARD 20)

message("call in client. CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

message("call in client. CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable( client 
    ${CMAKE_CURRENT_SOURCE_DIR}/client.cpp
)

target_link_libraries(client 
    PRIVATE
        core
        plog::plog
        Boost::program_options
)
