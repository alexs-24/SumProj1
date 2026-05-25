/**
 * @file DatabaseTests.cpp
 * @author alexs
 */

#include "../Database.h"
#include "../Transaction.h"
#include <iostream>
#include <gtest/gtest.h>

/**
 * test opening the database
 */
TEST(DatabaseTests, OpenDb)
{
    Database db;

    bool result = db.openDb();

    EXPECT_TRUE(result);
}

/**
 * test table creation
 */
TEST(DatabaseTests, TableTest)
{
    Database db;

    db.openDb();
    bool result = db.createTable();
    EXPECT_TRUE(result);
}

/**
 * test add transaction
 */
TEST(DatabaseTests, TransactionTest)
{
    Database db;
    db.openDb();

    db.createTable();

    double amount = 42.99;
    std::string category = "Food";
    std::string date = "5-24-2026";
    std::string description = "Groceries";
    TransactionType type = TransactionType::Expense;

    Transaction transaction(amount, category, date, description, type);

    bool result = db.addTransaction(transaction);

    EXPECT_TRUE(result);
}