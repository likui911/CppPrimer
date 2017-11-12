/*
 Define the addition and compound-assignment operators for your Sales_data class.
*/

#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
  public:
    friend istream &operator>>(istream &is, Sales_data &item);
    friend ostream &operator<<(ostream &os, const Sales_data &item);

    friend Sales_data &operator+(Sales_data &lhs, const Sales_data &rhs);

    Sales_data(string bk, unsigned un, double price)
        : bookNo(bk), unit_solds(un), revenue(un * price) {}

    Sales_data()
        : Sales_data("", 0, 0) {}

    Sales_data(const string &s)
        : Sales_data(s, 0, 0) {}

    Sales_data &operator+=(const Sales_data &rhs);

  private:
    string bookNo;
    unsigned unit_solds;
    double revenue;
};

istream &operator>>(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.unit_solds >> price;
    if (is)
    {
        item.revenue = item.unit_solds * price;
    }
    else
        item = Sales_data();
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.bookNo << "-" << item.unit_solds << "-" << item.revenue;
    return os;
}

Sales_data &Sales_Data::operator+=(const Sales_data &rhs)
{
    if (bookNo == rhs.bookNo)
    {
        unit_solds += rhs.unit_solds;
        revenue += rhs.revenue;
    }
    return *this;
}

Sales_data &operator+(Sales_data &lhs, const Sales_data &rhs)
{
    if (lhs.bookNo == rhs.bookNo)
    {
        lhs.unit_solds += rhs.unit_solds;
        lhs.revenue += rhs.revenue;
    }
    return lhs;
}