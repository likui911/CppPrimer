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

    for (auto i = integers.begin(), j = integers.end() - 1;; ++i, --j)
    {
        if (i == j)
            cout << *i << endl;
        else if (i < j)
            cout << *i + *j << endl;
        else
            break;
    }
    return 0;
}