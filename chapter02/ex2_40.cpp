#include <iostream>

struct Sales_data{
    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data item;
    std::cout<<"Please input the bookNo, unit_solds, revenue"<<std::endl;
    std::cin>>item.bookNo>>item.unit_solds>>item.revenue;
    std::cout<<item.bookNo<<std::endl;
    return 0;
}