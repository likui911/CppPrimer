/*
Use accumulate to sum the elements in a vector<int>.
*/
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec_i{1,2,3,4,5,6,78,5};
    int sum = accumulate(vec_i.cbegin(),vec_i.cend(),0);
    cout<<sum<<endl;
    return 0;
}