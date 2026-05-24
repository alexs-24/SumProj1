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

    db.closeDb();

    return 0;
}