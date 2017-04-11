/*
Given a vector that has ten elements, copy the elements
from positions 3 through 7 in reverse order to a list.
*/
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{   
    vector<int> vec_i{1,2,3,4,5,6,7,8,9,0};
    list<int> lis;
    auto beg = vec_i.begin();
    copy(beg+3,beg+8,front_inserter(lis));
    for(int i:lis)
    {
        cout<<i<<endl;
    }
    return 0;
}