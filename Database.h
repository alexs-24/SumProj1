/**
 * @file Database.h
 * @author alexs
 *
 *
 */

#ifndef SUMPROJ1_DATABASE_H
#define SUMPROJ1_DATABASE_H
#include <sqlite3.h>
#include <vector>

#include "Transaction.h"

class Database
{
private:
    sqlite3* db;
public:
    /**
     * constructor
     */
    Database();
    /**
     * destructor
     */
    ~Database();
    /**
     * Open database
     * @return True if successful
     */
    bool openDb();
    /**
     * Check if database is open and close if so
     */
    void closeDb();
    /**
     * Create the sql table
     */
    bool createTable();
    /**
     * add the transaction to our database
     * @param transaction
     * @return True/false for if successfully added
     */
    bool addTransaction(const Transaction& transaction);
    /**
     * output our current transactions
     * @return
     */
    std::vector<Transaction> getAllTransactions();
};


#endif //SUMPROJ1_DATABASE_H