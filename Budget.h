/**
 * @file Budget.h
 * @author alexs
 *
 *
 */

#ifndef SUMPROJ1_BUDGET_H
#define SUMPROJ1_BUDGET_H

#include <string>

class Budget
{
private:
    std::string category;

    double limit;

    int id;
public:

    Budget(std::string category, double limit);

    std::string getCategory() const {return category;}
    double getLimit() const {return limit;}

    void SetId(int set_id) {id = set_id;}
};


#endif //SUMPROJ1_BUDGET_H