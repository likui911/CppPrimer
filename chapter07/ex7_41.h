#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#ifndef EX7_41_H
#define EX7_41_H

class Sales_data
{
  public:
    friend istream &read(istream &is, Sales_data item);
    friend ostream &print(ostream &os, Sales_data item);

    Sales_data(string bk, unsigned un, double price) : bookNo(bk), unit_solds(un), revenue(un * price)
    {
        cout << "Sales_data(string, unsigned, double)" << endl;
    };

    Sales_data() : Sales_data("", 0, 0)
    {
        cout << "Sales_data()" << endl;
    };

    Sales_data(const string &s) : Sales_data(s, 0, 0)
    {
        cout << "Sales_data(string)" << endl;
    };

    Sales_data(istream &is) : Sales_data()
    {
        cout << "Sales_data(istream)" << endl;
        read(is, *this);
    };

  private:
    string bookNo;
    unsigned unit_solds;
    double revenue;
};

istream &read(istream &is, Sales_data item);

ostream &print(ostream &os, Sales_data item);

#endif // !EX7_41_H