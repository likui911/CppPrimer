/*
Define a variable that you initialize by calling begin() on
the multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s
type without using auto or decltype.
*/
#include "../chapter01/Sales_item.h"
#include <set>
using namespace std;

// this function define in Sales_item.h
// bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
// {
//     return lhs.isbn() < rhs.isbn();
// }

int main()
{
    using compareType = bool (*)(const Sales_item &lhs, const Sales_item &rhs);
    multiset<Sales_item, compareType> bookstore(compareIsbn);
    std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
    return 0;
}
