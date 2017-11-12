/*
Exercise 14.8: Define an output operator for the class you chose in
exercise 7.40 from § 7.5.1 (p. 291).
*/
#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
  public:
    friend istream &operator>>(istream &is, Sales_data &item);
    friend ostream &operator<<(ostream &os, const Sales_data &item);

    Sales_data(string bk, unsigned un, double price)
        : bookNo(bk), unit_solds(un), revenue(un * price) {}

    Sales_data()
        : Sales_data("", 0, 0) {}

    Sales_data(const string &s)
        : Sales_data(s, 0, 0) {}

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
