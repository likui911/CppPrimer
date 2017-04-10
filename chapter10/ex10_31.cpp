/*
 Update the program from the previous exercise so that it
 prints only the unique elements. Your program should use unqiue_copy (§
 10.4.1, p. 403).
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
    //copy and sort element
    copy(int_iter, eos, back_inserter(vec_i));
    sort(vec_i.begin(), vec_i.end());

    //unique_copy to ostream_iterator
    ostream_iterator<int> out_iter(cout, " ");
    unique_copy(vec_i.begin(), vec_i.end(), out_iter);

    return 0;
}