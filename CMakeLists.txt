cmake_minimum_required(VERSION 4.1)
project(SumProj1)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        sqlite3
        URL https://www.sqlite.org/2026/sqlite-amalgamation-3510200.zip
)

FetchContent_MakeAvailable(sqlite3)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
        SumProj1
        main.cpp
        Database.cpp
        Transaction.cpp
)

target_include_directories(
        SumProj1
        PRIVATE
        ${sqlite3_SOURCE_DIR}
)

target_sources(
        SumProj1
        PRIVATE
        ${sqlite3_SOURCE_DIR}/sqlite3.c
)

add_executable(
        Tests
        tests/TransactionTests.cpp
        tests/DatabaseTests.cpp
        Transaction.cpp
        Database.cpp
)

target_include_directories(
        Tests
        PRIVATE
        ${sqlite3_SOURCE_DIR}
)

target_sources(
        Tests
        PRIVATE
        ${sqlite3_SOURCE_DIR}/sqlite3.c
)

target_link_libraries(
        Tests
        GTest::gtest_main
)