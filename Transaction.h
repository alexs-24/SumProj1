/**
 * @file Transaction.h
 * @author alexs
 *
 *
 */

#ifndef SUMPROJ1_TRANSACTION_H
#define SUMPROJ1_TRANSACTION_H
#include <string>

/*
 * To keep track of the types of transactions
 */
enum class TransactionType
{
    Income, Expense
};

class Transaction
{
private:
    /// id of the transaction
    int id;
    /// amount of the transaction
    double amount;
    /// category of the transaction
    std::string category;
    /// date of the transaction
    std::string date;
    /// description of the transaction
    std::string description;
    /// what type of transaction
    /// uses the enumeration
    TransactionType type;
public:
    /**
     * Constructor
     */
    Transaction(double amount, std::string category, std::string date, std::string description, TransactionType type);
    /**
     * display the transaction for the user
     */
    void display();
    /// getter for the amount
    double getAmount() const {return amount;}
    /// getter for the category
    std::string getCategory() const {return category;}
    /// getter for the date
    std::string getDate() const {return date;}
    /// getter for the description
    std::string getDescription() const {return description;}
    /// getter for the type
    TransactionType getType() const {return type;}

    void setId(int set_id) {id = set_id;}
};


#endif //SUMPROJ1_TRANSACTION_H