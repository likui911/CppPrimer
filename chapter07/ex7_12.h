#include <iostream>
#include <string>

#ifndef EX7_12_H
#define EX7_12_H

struct Sales_data;
std::istream &read(std::istream &is, Sales_data &item);

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), unit_solds(n), revenue(p * n){};
    Sales_data(std::istream &is) { read(is, *this); }

    const std::string isbn() const { return bookNo; }
    Sales_data &combine(Sales_data &rhs);

    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0;
};

Sales_data &Sales_data::combine(Sales_data &rhs)
{
    unit_solds += rhs.unit_solds;
    revenue += rhs.revenue;
    return *this;
}

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
