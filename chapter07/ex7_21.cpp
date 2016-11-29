#include "ex7_21.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_data total = Sales_data(cin);
    if (!total.isbn().empty())
    {
        std::istream &is = cin;
        Sales_data trans;
        while (is)
        {
            trans = Sales_data(is);
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cerr << "No Data?" << endl;
        return -1;
    }

    return 0;
}