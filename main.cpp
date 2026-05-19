/**
 * @file main.cpp
 * @author alexs
 */

#include <iostream>
#include <sqlite3.h>

/// this is a test
int main() {

    sqlite3* db;

    int result = sqlite3_open("../finance.db", &db);

    if(result == SQLITE_OK)
    {
        std::cout << "Database connected successfully\n";
    }
    else
    {
        std::cout << "Connection failed\n";
    }

    sqlite3_close(db);

    return 0;
}