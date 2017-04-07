/*
Copy a vector that holds the values from 1 to 9 inclusive,
into three other containers. Use an inserter, a back_inserter, and a
front_inserter, respectivly to add elements to these containers. Predict
how the output sequence varies by the kind of inserter and verify your
predictions by running your programs.
*/

#include <iterator>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1{};
    list<int> v2{};
    vector<int> v3{};
    mtx.lock();
    // 1,2,3,4,5,6,7,8,9
    copy(vi.begin(), vi.end(), back_inserter(v1));
    //9,8,7,6,5,4,3,2,1
    copy(vi.begin(), vi.end(), front_inserter(v2));
    //1,2,3,4,5,6,7,8,9
    copy(vi.begin(), vi.end(), inserter(v3, v3.begin()));
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v3)
    {
        cout << i << " ";
    }
    return 0;
}