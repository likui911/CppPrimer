/*
Assuming v is a vector<double>, what, if anything, is wrong
with calling accumulate(v.cbegin(), v.cend(), 0)?
*/
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
    vector<double> vec_d{1.1, 2.2, 3.3, 4.0, 5.0, 6.0, 78.0, 5.0};
    // sum==104
    double sum_i = accumulate(vec_d.cbegin(), vec_d.cend(), 0);
    cout << sum_i << endl;
    // sum==104.6
    double sum_d = accumulate(vec_d.cbegin(), vec_d.cend(), 0.0);
    cout << sum_d << endl;
    return 0;
}