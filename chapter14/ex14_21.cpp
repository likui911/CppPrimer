/*
Write the Sales_data operators so that + does the actual
addition and += calls +. Discuss the disadvantages of this approach
compared to the way these operators were defined in § 14.3 (p. 560) and
§ 14.4 (p. 564).
*/
#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
  public:
    friend istream &operator>>(istream &is, Sales_data &item);
    friend ostream &operator<<(ostream &os, const Sales_data &item);

    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

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

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    *this = *this + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.unit_solds = lhs.unit_solds + rhs.unit_solds;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

int main()
{
    Sales_data s1("1", 3, 23);
    Sales_data s2("1", 4, 23);
    s1 += s2;
    cout << s1 << endl;
    return 0;
}