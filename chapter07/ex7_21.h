#include <iostream>
#include <string>

#ifndef EX7_21_H
#define EX7_21_H

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &sl);
    friend std::ostream &print(std::ostream &os, Sales_data &sl);

  public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(std::istream &is){read(is,*this);}

    Sales_data &combine(Sales_data &rhs);
    const std::string &isbn()const{return bookNo;};

  private:
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

Sales_data &Sales_data::combine(Sales_data &rhs)
{
    unit_solds += rhs.unit_solds;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &sl)
{
    double price;
    is >> sl.bookNo >> sl.unit_solds >> price;
    sl.revenue = sl.unit_solds * price;
    return is;
}

std::ostream &print(std::ostream &os, Sales_data &sl)
{
    os << sl.bookNo << " " << sl.unit_solds << " " << sl.revenue << std::endl;
    return os;
}

#endif // !EX7_21_H
