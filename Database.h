/**
 * @file Database.h
 * @author alexs
 *
 *
 */

#ifndef SUMPROJ1_DATABASE_H
#define SUMPROJ1_DATABASE_H
#include <sqlite3.h>
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

    bool addTransaction(const Transaction& transaction);
};


#endif //SUMPROJ1_DATABASE_H