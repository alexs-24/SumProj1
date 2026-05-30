/**
 * @file Database.cpp
 * @author alexs
 */

#include "Database.h"
#include "Transaction.h"
#include <iostream>
#include <string>

static int GetTransactionsCallback(void* data,
                                   int argc,
                                   char** argv,
                                   char** columnNames)
{
    auto transactions = static_cast<std::vector<Transaction>*>(data);

    int c_id = std::stoi(argv[0]);

    std::string type = argv[1];
    TransactionType c_type;
    if (type == "Income") {c_type = TransactionType::Income;}
    else {c_type = TransactionType::Expense;}

    double c_amount = std::stod(argv[2]);

    std::string c_category = argv[3];

    std::string c_date = argv[4];

    std::string c_description = argv[5];

    Transaction transaction(c_amount, c_category, c_date, c_description, c_type);
    transaction.setId(c_id);

    transactions->push_back(transaction);

    return 0;
}

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

bool Database::createTable()
{
    std::string query = "CREATE TABLE IF NOT EXISTS transactions(id INTEGER PRIMARY KEY AUTOINCREMENT, type TEXT, amount REAL, category TEXT, date TEXT, description TEXT)";

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

    if (result == SQLITE_OK)
    {
        std::cout << "Table successfully created, or already exists" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Table not successful";
        return false;
    }
}

bool Database::addTransaction(const Transaction& transaction)
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
        std::cout << "Information successfully added" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Information not successful, Error: " << result << std::endl;
        return false;
    }
}

std::vector<Transaction> Database::getAllTransactions()
{
    std::vector<Transaction> transactions;

    std::string query = "SELECT * FROM transactions";

    sqlite3_exec(db, query.c_str(), GetTransactionsCallback, &transactions, nullptr);

    return transactions;
}