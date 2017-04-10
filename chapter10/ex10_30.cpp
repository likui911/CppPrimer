/*
Use stream iterators, sort, and copy to read a sequence
of integers from the standard input, sort them, and then write them back
to the standard output.
*/
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> int_iter(cin), eos;
    vector<int> vec_i;
    //copy element to vector<int>
    copy(int_iter, eos, back_inserter(vec_i));
    //sort vector<int>
    sort(vec_i.begin(), vec_i.end());

    //print testing result
    for (int i : vec_i)
    {
        cout << i << endl;
    }
    return 0;
}