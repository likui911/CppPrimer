#include <iostream>

using namespace std;

//type alias
using arrT = int[10];
arrT &getABSValue1(arrT &ia)
{
    for (int &i : ia)
    {
        i = i > 0 ? i : 0 - i;
    }
    return ia;
}

//trailing return,返回值必须是auto
auto getABSValue2(int (&ia)[10]) -> int (&)[10]
{
    for (int &i : ia)
    {
        i = i > 0 ? i : 0 - i;
    }
    return ia;
}

//decltype
int arr[10] = {0};
decltype(arr) &getABSValue3(decltype(arr) &ia)
{
    for (int &i : ia)
    {
        i = i > 0 ? i : 0 - i;
    }
    return ia;
}

int main()
{
    int ia[10] = {1, 2, -3, -4, 5, 6, -7, 8, -9, 4};
    for (int i : getABSValue1(ia))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}