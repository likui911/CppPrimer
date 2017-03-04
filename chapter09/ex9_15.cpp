#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec_1{1, 2, 3, 4, 5};
    vector<int> vec_2{1, 2, 3, 4, 5, 6};
    if (vec_1 == vec_2)
    {
        cout << "EQUAL" << endl;
    }
    else
    {
        cout << "UNEQUAL" << endl;
    }
    return 0;
}