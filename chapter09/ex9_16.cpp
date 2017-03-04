#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> ls_1{1, 2, 3, 4, 5};
    vector<int> vec_2{1, 2, 3, 4, 5};
    if (ls_1 == list<int>(vec_2.begin(), vec_2.end()))
    {
        cout << "EQUAL" << endl;
    }
    else
    {
        cout << "UNEQUAL" << endl;
    }
    return 0;
}