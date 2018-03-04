#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int i = 1024;
    double d = 2016;
    cout<<std::max<double>(i, d)<<endl;
    return 0;
}