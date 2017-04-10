/*
Rewrite the bookstore problem from § 1.6 (p. 24) using
a vector to hold the transactions and various algorithms to do the
processing. Use sort with your compareIsbn function from § 10.3.1 (p. 387)
to arrange the transactions in order, and then use find and accumulate to
do the sum.
*/

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include "../chapter01/Sales_item.h"

using namespace std;

int main()
{
    //using a vector to hold transactions
    istream_iterator<Sales_item> iss(cin), eos;
    vector<Sales_item> vecs;
    copy(iss, eos, back_inserter(vecs));
    //sort it
    auto compareIsbn = [](const Sales_item &lhs, const Sales_item &rhs) { return lhs.isbn() < rhs.isbn(); };
    sort(vecs.begin(), vecs.end(), compareIsbn);

    for (auto beg = vecs.cbegin(); beg != vecs.cend();)
    {
        //循环累加，并输出
        auto idx = find_if(beg, vecs.cend(), [beg](const Sales_item &rhs) { return (*beg).isbn() != rhs.isbn(); });
        cout << accumulate(beg, idx, Sales_item(beg->isbn())) << endl;
        beg = idx;
    }

    return 0;
}