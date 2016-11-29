#include <iostream>
#include <string>

#ifndef EX7_2_H
#define EX7_2_H

struct Sales_data
{
    std::string isbn() const;
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0;
};

std::string Sales_data::isbn() const
{
    return bookNo;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    unit_solds += rhs.unit_solds;
    revenue += rhs.revenue;
    return *this;
}

#endif
