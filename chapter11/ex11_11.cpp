#include "../chapter07/ex7_26.h"
#include <set>
using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

// bookstore can have several transactions with the same ISBN
// elements in bookstore will be in ISBN order
// ##########using decltype#############
multiset<Sales_data, decltype(compareIsbn) *>
    bookstore(compareIsbn);

int main()
{
    using CompareType = bool (*)(const Sales_data &, const Sales_data &);
    multiset<Sales_data, CompareType>
        bookstore(compareIsbn);

    return 0;
}
