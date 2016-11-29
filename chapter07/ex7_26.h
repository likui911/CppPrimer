#include <iostream>
#include <string>

#ifndef EX7_26_H
#define EX7_26_H

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &sl);
    friend std::ostream &print(std::ostream &os, Sales_data &sl);

  public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(std::istream &is) { read(is, *this); }

    Sales_data &combine(Sales_data &rhs);
    inline double avg_price() const;
    const std::string &isbn() const { return bookNo; };

  private:
    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0;
};

double Sales_data::avg_price() const
{
    return unit_solds ? revenue / unit_solds : 0;
}

// 声明非成员函数
Sales_data add(Sales_data &lhs, Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &sl);
std::ostream &print(std::ostream &os, Sales_data &sl);

#endif // !EX7_21_H
