/**
 * @file Budget.cpp
 * @author alexs
 */

#include "Budget.h"

Budget::Budget(const std::string category, double limit)
{
    this->category = category;
    this->limit = limit;
}