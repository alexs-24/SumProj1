/**
 * @file Database.cpp
 * @author alexs
 */

#include "Database.h"
#include "Transaction.h"
#include <iostream>
#include <string>

/**
 *
 * @param data transactions from db
 * @param argc num of rows
 * @param argv data in transactions
 * @param columnNames
 * @return 0 to signal we got the transactions from database
 */
static int GetTransactionsCallback(void* data, int argc, char** argv, char** columnNames)
{
    auto transactions = static_cast<std::vector<Transaction>*>(data);

    int c_id = std::stoi(argv[0]);

    std::string type = argv[1]; /// convert type
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

static int GetBudgetsCallback(void* data, int argc, char** argv, char** columnNames)
{
    auto budgets = static_cast<std::vector<Budget>*>(data);

    int c_id = std::stoi(argv[0]);

    std::string c_category = argv[1];

    double c_limit = std::stod(argv[2]);

    Budget budget(c_category, c_limit);
    budget.SetId(c_id);

    budgets->push_back(budget);

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
        sqlite3_close(db); /// close the connection
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

    if (result == SQLITE_OK) /// created table successfully
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

/**
 * Create a table for budget
 * Helps us to keep track of different things we want to budget
 * @return
 */
bool Database::createBudgetTable()
{
    std::string query = "CREATE TABLE IF NOT EXISTS budget(id INTEGER PRIMARY KEY AUTOINCREMENT, category TEXT, BudgetLimit REAL)";

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

    if (result == SQLITE_OK)
    {
        std::cout << "Budget table successfully created" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Budget table not created" << std::endl;
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
    if (result == SQLITE_OK) /// successfully added transaction to database
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

bool Database::addBudget(const Budget& budget)
{
    /// Get the values
    std::string category = budget.getCategory();
    double limit = budget.getLimit();

    std::string query = "INSERT INTO budget(category, BudgetLimit) VALUES('" + category + "', " + std::to_string(limit) + ")";

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
    if (result == SQLITE_OK) /// successfully added transaction to database
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

std::vector<Budget> Database::getAllBudgets()
{
    std::vector<Budget> budgets;

    std::string query = "SELECT * FROM budget";

    sqlite3_exec(db, query.c_str(), GetBudgetsCallback, &budgets, nullptr);

    return budgets;
}

std::vector<Transaction> Database::getAllTransactions()
{
    std::vector<Transaction> transactions; /// vector to store the transactions we get

    std::string query = "SELECT * FROM transactions"; /// sql query for transactions

    sqlite3_exec(db, query.c_str(), GetTransactionsCallback, &transactions, nullptr);

    return transactions;
}

void Database::DeleteTransaction()
{
    auto transactions  = getAllTransactions();

    for (Transaction& t : transactions)
    {
        t.display();
    }

    int id;
    std::cout << "What is the id of the transaction you would like to delete?" << std::endl;
    std::cin >> id;
    /// run a query to check the id the user gave
    /// need a helper function


    std::string query = "DELETE FROM transactions WHERE id = " + std::to_string(id);

    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

    if (result == SQLITE_OK) /// successfully deleted transaction
    {
        std::cout << "Information successfully deleted" << std::endl;
    }
    else
    {
        std::cout << "Information not deleted, Error: " << result << std::endl;
    }
}
