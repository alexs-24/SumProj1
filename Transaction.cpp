/**
 * @file Transaction.cpp
 * @author alexs
 */

#include "Transaction.h"

#include <iostream>

Transaction::Transaction(double amount, std::string category, std::string date, std::string description, TransactionType type)
{
    this->amount = amount;
    this->category = category;
    this->date = date;
    this->description = description;
    this->type = type;
}

void Transaction::display()
{
    std::cout << "Amount: " << amount << std::endl <<
        "Category: " << category << std::endl <<
            "Date: " << date << std::endl <<
                "Description: " << description << std::endl;
    if (type == TransactionType::Income)
    {
        std::cout << "Transaction Type: Income" << std::endl;
    }
    else
    {
        std::cout << "Transaction Type: Expense" << std::endl;
    }
}