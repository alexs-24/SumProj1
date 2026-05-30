/**
 * @file main.cpp
 * @author alexs
 */

#include <iostream>
#include <sqlite3.h>
#include "Transaction.h"
#include "Database.h"

/// this is a test
int main() {

    Database db;

    if (db.openDb()) std::cout << "Database successfully created!" << std::endl;
    else std::cout << "Database failed to create!" << std::endl;

    db.createTable();

    double amount = 42.99;
    std::string category = "Food";
    std::string date = "5-24-2026";
    std::string description = "Groceries";
    TransactionType type = TransactionType::Expense;

    Transaction transaction(amount, category, date, description, type);

    db.addTransaction(transaction);

    amount = 45.99;
    category = "Food";
    date = "5-29-2026";
    description = "Mcdonalds";
    type = TransactionType::Expense;

    Transaction transaction2(amount, category, date, description, type);

    db.addTransaction(transaction2);

    auto transactions = db.getAllTransactions();

    for (Transaction& t : transactions)
    {
        t.display();
    }

    db.closeDb();

    return 0;
}