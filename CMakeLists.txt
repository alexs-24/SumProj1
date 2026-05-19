cmake_minimum_required(VERSION 4.1)
project(SumProj1)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        sqlite3
        URL https://www.sqlite.org/2026/sqlite-amalgamation-3510200.zip
)

FetchContent_MakeAvailable(sqlite3)

add_executable(SumProj1 main.cpp)

target_include_directories(SumProj1 PRIVATE ${sqlite3_SOURCE_DIR})

target_sources(SumProj1 PRIVATE
        ${sqlite3_SOURCE_DIR}/sqlite3.c
)
