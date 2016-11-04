#include <iostream>
#include <string.h>

using namespace std;

struct Sales_data{
    string bookNo;
    unsigned unit_solds;
    double revenue;
};

int main()
{
    Sales_data total;
    if(cin>>total.bookNo>>total.unit_solds>>total.revenue)
    {
        Sales_data trans;
        while(cin>>trans.bookNo>>trans.unit_solds>>trans.revenue)
        {
            if(total.bookNo==trans.bookNo)
            {
                total.unit_solds+=trans.unit_solds;
                total.revenue+=trans.revenue;
            }
            else{
                cout<<total.bookNo<<" "<<total.unit_solds<<" "<<total.revenue<<endl;
                total.bookNo = trans.bookNo;
                total.unit_solds = trans.unit_solds;
                total.revenue = trans.revenue;
            }
        }
    }else{
        cerr<<"No Data ?"<<endl;
        return -1;
    }

    return 0;
}