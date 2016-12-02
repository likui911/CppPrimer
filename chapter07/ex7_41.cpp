#include "ex7_41.h"

istream &read(istream &is, Sales_data item)
{
    double price;
    is >> item.bookNo >> item.unit_solds >> price;
    item.revenue = item.unit_solds * price;
    return is;
};

ostream &print(ostream &os, Sales_data item)
{
    os << item.bookNo << " " << item.unit_solds << " " << item.revenue;
    return os;
};

int main()
{
    Sales_data s1;
    Sales_data s2 = Sales_data("ISO-900-1");
    return 0;
}