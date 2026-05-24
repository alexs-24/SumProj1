/**
 * @file Database.cpp
 * @author alexs
 */

#include "Database.h"
#include "Transaction.h"
#include <iostream>
#include <string>

Database::Database()
{
    db = nullptr;
}

Database::~Database()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::openDb()
{
    int result = sqlite3_open("../finance.db", &db);
    if (result == SQLITE_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Database::closeDb()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

void Database::createTable()
{
    std::string query = "CREATE TABLE IF NOT EXISTS transactions(id INTEGER PRIMARY KEY AUTOINCREMENT, type TEXT, amount REAL, category TEXT, date TEXT, description TEXT)";

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

    if (result == SQLITE_OK)
    {
        std::cout << "Table successfully created, or already exists" << std::endl;
    }
    else
    {
        std::cout << "Table not successful";
    }
}

void Database::addTransaction(const Transaction& transaction)
{
    /// extract the values
    double amount = transaction.getAmount();
    std::string category = transaction.getCategory();
    std::string date = transaction.getDate();
    std::string description = transaction.getDescription();
    TransactionType type = transaction.getType();

    /// convert transaction type
    std::string typeText; /// initialize before if statement
    if (type == TransactionType::Income)
    {
        typeText = "Income";
    }
    else
    {
        typeText = "Expense";
    }

    /// build query
    std::string query = "INSERT INTO transactions(type, amount, category, date, description) VALUES('" + typeText + "', " + std::to_string(amount) + ", '" + category + "', '" + date + "', '" + description + "')";

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
    if (result == SQLITE_OK)
    {
        std::cout << "Information successfully added";
    }
    else
    {
        std::cout << "Information not successful, Error: " << result << std::endl;
    }
}