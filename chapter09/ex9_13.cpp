#include <vector>
#include <list>
#include <iostream>

using namespace std;


int main()
{
    list<int> li{1,2,3,4,5,6,7,8,9};
    vector<double> vec_d(li.begin(),li.end());
    for(auto d:vec_d)
    {
        cout<<d<<endl;
    }

    return 0;
}