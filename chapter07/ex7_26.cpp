#include "ex7_26.h"
#include <iostream>
#include <string>

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

// int main()
// {
//     Sales_data total;
//     std::istream &is = std::cin;
//     if (is)
//     {
//         total = Sales_data(is);
//         std::istream &is = std::cin;
//         Sales_data trans;
//         while (is)
//         {
//             trans = Sales_data(is);
//             if (trans.isbn() == total.isbn())
//             {
//                 total.combine(trans);
//             }
//             else
//             {
//                 print(std::cout, total);
//                 total = trans;
//             }
//         }
//         print(std::cout, total);
//     }
//     else
//     {
//         std::cerr << "No Data?" << std::endl;
//         return -1;
//     }

//     return 0;
// }