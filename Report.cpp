/**
 * @file Report.cpp
 * @author alexs
 */

#include "Report.h"

Report::Report(const std::vector<Transaction>& transactions2)
{
    this->transactions = transactions2;
}

double Report::getExpenses()
{
    double total = 0;
    for (const auto& transaction : transactions)
    {
        TransactionType type = transaction.getType();
        if (type == TransactionType::Expense)
        {
            double amount = transaction.getAmount();
            total += amount;
        }
    }

    return total;
}

double Report::getIncomes()
{
    double total = 0;
    for (const auto& transaction : transactions)
    {
        TransactionType type = transaction.getType();
        if (type == TransactionType::Income)
        {
            double amount = transaction.getAmount();
            total += amount;
        }
    }

    return total;
}

double Report::getBalance()
{
    double expenses = getExpenses();
    double incomes = getIncomes();

    return incomes - expenses;
}