/**
 * @file TransactionTests.cpp
 * @author alexs
 */

#include "../Transaction.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>

/**
 * testing our constructor and getters
 */
TEST(TransactionTests, ConstructorTest)
{

    double amount = 42.99;
    std::string category = "Food";
    std::string date = "5-24-2026";
    std::string description = "Groceries";
    TransactionType type = TransactionType::Expense;

    Transaction transaction(amount, category, date, description, type);

    double get_amount = transaction.getAmount();
    EXPECT_DOUBLE_EQ(get_amount, amount);

    std::string get_category = transaction.getCategory();
    ASSERT_EQ(get_category, category);

    std::string get_date = transaction.getDate();
    ASSERT_EQ(get_date, date);

    std::string get_description = transaction.getDescription();
    ASSERT_EQ(get_description, description);

    TransactionType get_type = transaction.getType();
    ASSERT_EQ(get_type, type);
}

/**
 * Test our other type (income) that we created
 */
TEST(TransactionTests, TypeTest)
{
    double amount = 42.99;
    std::string category = "Food";
    std::string date = "5-24-2026";
    std::string description = "Groceries";
    TransactionType type = TransactionType::Income;

    Transaction transaction(amount, category, date, description, type);

    TransactionType get_type = transaction.getType();
    ASSERT_EQ(get_type, type);
}

/**
 * test multiple transactions
 */
TEST(TransactionTests, MultipleTransactionTest)
{
    double amount = 42.99;
    std::string category = "Food";
    std::string date = "5-24-2026";
    std::string description = "Groceries";
    TransactionType type = TransactionType::Expense;

    Transaction transaction1(amount, category, date, description, type);

    double amount_2 = 1000;
    std::string category_2 = "Salary";
    std::string date_2 = "5-25-2026";
    std::string description_2 = "Pay";
    TransactionType type_2 = TransactionType::Income;

    Transaction transaction2(amount_2, category_2, date_2, description_2, type_2);


    double getAmount1 = transaction1.getAmount();
    EXPECT_DOUBLE_EQ(getAmount1, amount);
    double getAmount2 = transaction2.getAmount();
    EXPECT_DOUBLE_EQ(getAmount2, amount_2);

    std::string getCategory1 = transaction1.getCategory();
    ASSERT_EQ(getCategory1, category);
    std::string getCategory2 = transaction2.getCategory();
    ASSERT_EQ(getCategory2, category_2);

    std::string getDate1 = transaction1.getDate();
    ASSERT_EQ(getDate1, date);
    std::string getDate2 = transaction2.getDate();
    ASSERT_EQ(getDate2, date_2);

    std::string getDescription1 = transaction1.getDescription();
    ASSERT_EQ(getDescription1, description);
    std::string getDescription2 = transaction2.getDescription();
    ASSERT_EQ(getDescription2, description_2);

    TransactionType getType1 = transaction1.getType();
    ASSERT_EQ(getType1, type);
    TransactionType getType2 = transaction2.getType();
    ASSERT_EQ(getType2, type_2);
}