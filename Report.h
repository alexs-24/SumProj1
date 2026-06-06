/**
 * @file Report.h
 * @author alexs
 *
 *
 */

#ifndef SUMPROJ1_REPORT_H
#define SUMPROJ1_REPORT_H

#include "Transaction.h"
#include <vector>

class Report
{
private:
    std::vector<Transaction> transactions;
public:
    /**
     * Constructor
     * Gets the vector of our data from transaction
     * @param transactions
     */
    Report(const std::vector<Transaction>& transactions);
    /**
     * Get the total of the users expenses
     * @return total
     */
    double getExpenses();
    /**
     * Get the total of the users income
     * @return total
     */
    double getIncomes();
    /**
     * Get the total of the incomes and expenses of the user
     * @return total
     */
    double getBalance();
};


#endif //SUMPROJ1_REPORT_H