#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item total;

    // read the first transaction
    if(cin>>total)
    {
        Sales_item trans;
        while(cin>>trans)
        {
            if(total.isbn()==trans.isbn())
                total+=trans;
            else
            {
                //print result for previous book
                cout<<total<<endl;
                total = trans;
            }
        }
    }else{
        cerr<<"No Data ?"<<endl;
        return -1;
    }
    return 0;
}