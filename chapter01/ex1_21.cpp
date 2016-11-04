#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item item_1, item_2;
    //   in >> s.bookNo >> s.units_sold >> price;
    cout << "Please input two items (Input bookNo units_sold price): " << endl;
    cin >> item_1 >> item_2;
    if (item_1.isbn() == item_2.isbn())
    {
        cout << item_1 + item_2 << endl;
        return 0;
    }
    else
    {
        cerr << "Data must refer to same ISBN." << endl;
        return -1;
    }
}