#include <iostream>
#include <string>

#ifndef EX7_6_H
#define EX7_6_H

struct Sales_data
{
    const std::string isbn() const { return bookNo; }

    Sales_data &combine(Sales_data &rhs)
    {
        unit_solds += rhs.unit_solds;
        revenue += rhs.revenue;
        return *this;
    }

    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0;
};

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.unit_solds >> price;
    item.revenue = price * item.unit_solds;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.unit_solds << " " << item.revenue << std::endl;
    return os;
}

#endif
