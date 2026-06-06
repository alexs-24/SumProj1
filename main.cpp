/**
 * @file main.cpp
 * @author alexs
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sqlite3.h>
#include "Transaction.h"
#include "Database.h"
#include "Report.h"
#include "Budget.h"

using namespace std;

void displayMenu()
{
    std::cout << endl << "Options:" << endl <<
        "1: Add Transaction" << endl <<
        "2: View Transactions" << endl <<
        "3: Delete Transaction" << endl <<
        "4: View Report" << endl <<
        "5: Add Budget" << endl <<
        "6: View Budgets" << endl <<
        "7: Exit" << endl;
}

void getTransaction(double& amount, string& category, string& date, string& description, TransactionType& type)
{
    cout << "What was the amount of your transaction: ";
    cin >> amount;

    cout <<  "What is the category of your transaction: ";
    cin >> category;

    cout <<  "What was the date of this transaction (XX/XX/XXXX): ";
    cin >> date;

    cout <<  "What is the description of your transaction: ";
    cin >> description;

    bool valid = false;

    while (!valid)
    {
        cout <<  "What is the type of your transaction (expense, income): ";
        string typeText;
        cin >> typeText;

        for (char& c : typeText)
        {
            c = tolower(c);
        }

        if (typeText == "income") {type = TransactionType::Income; valid = true;}
        else if (typeText == "expense") {type = TransactionType::Expense; valid = true;}
        else {cout << "Not a valid transaction type entered." << endl;}
    }
}

/// this is how the user adds data and deletes data
int main() {

    Database db;
    db.openDb();

    db.createTable();
    db.createBudgetTable();

    bool exit = false;
    int option;

    while (exit != true)
    {
        displayMenu();
        std::cin >> option;

        switch (option)
        {
        case 1: /// add a transaction to the database
            {
                double amount;
                string category;
                string date;
                string description;
                TransactionType type;

                getTransaction(amount, category, date, description, type);

                Transaction transaction(amount, category, date, description, type);
                db.addTransaction(transaction);

                break;
            }

        case 2: /// display current transactions
            {
                vector<Transaction> transactions;
                transactions = db.getAllTransactions();

                for (const Transaction& t : transactions)
                {
                    t.display();
                }

                break;
            }

        case 3: /// Delete a transaction
            {
                db.DeleteTransaction();
                break;
            }

        case 4:
            {
                vector<Transaction> transactions;
                transactions = db.getAllTransactions();
                Report report(transactions);

                double expense_total = report.getExpenses();
                double income_total = report.getIncomes();
                double balance_total = report.getBalance();

                cout << "Expenses Total: " << expense_total << endl;
                cout << "Incomes Total: " << income_total << endl;
                cout << "Balance Total: " << balance_total << endl;

                break;
            }
        case 5:
            {
                break;
            }

        case 6:
            {
                break;
            }

        case 7:
            {
                exit = true;
                break;
            }
        }
    }

    db.closeDb();

    return 0;
}