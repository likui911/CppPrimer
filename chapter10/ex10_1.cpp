/*
The algorithm header defines a function named count that,
like find, takes a pair of iterators and a value. count returns a count of
how often that value appears. Read a sequence of ints into a vector and
print the count of how many elements have a given value.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::count;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec_i{1,2,3,4,5,6,7,85,3,22,3,5,6,3,6,1,4,67};
    int i=count(vec_i.begin(),vec_i.end(),3);
    cout<<i<<endl;

    return 0;
}