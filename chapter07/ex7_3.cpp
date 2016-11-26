#include "ex7_2.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.unit_solds >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.unit_solds >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo << " " << total.unit_solds << " "
                     << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.unit_solds << " "
             << total.revenue << endl;
    }
    else
    {
        cerr << "No Data?" << endl;
        return -1;
    }

    return 0;
}