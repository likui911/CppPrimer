/*
 Use find to find the last element in a list of ints with
 value 0.
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,0,7,4,6,0,1,2,0};
    auto idx=find(vec.crbegin(),vec.crend(),0); 
    return 0;
}