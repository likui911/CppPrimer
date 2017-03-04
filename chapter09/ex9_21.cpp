#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec_i;
    vector<int>::iterator iter = vec_i.begin();
    int i;
    while (cin >> i)
    {
        iter = vec_i.insert(iter, i);
    }

    for (int i : vec_i)
    {
        cout << i << " ";
    }

    return 0;
}