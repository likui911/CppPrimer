#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> integers;

    int temp;
    while (cin >> temp)
    {
        integers.push_back(temp);
    }

    for (int i = 0;; ++i)
    {
        if (i < integers.size() - i - 1)
        {
            cout << integers[i] + integers[integers.size() - i - 1] << endl;
        }
        else if (i == integers.size() - i - 1)
        {
            cout << integers[i] << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}