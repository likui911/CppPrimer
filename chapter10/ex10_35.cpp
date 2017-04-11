/*
Now print the elements in reverse order using ordinary
iterators.
*/
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,0}; 
    reverse(vec.begin(),vec.end());
    for(auto i:vec)
    {
        cout<<i<<endl;
    }
    return 0;
}