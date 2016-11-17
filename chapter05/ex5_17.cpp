#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 2, 3, 7, 9};
    vector<int> v2 = {1, 2, 2};

    size_t size = v1.size() > v2.size() ? v2.size() : v1.size();

    for (int i = 0; i < size; ++i)
    {
        if (v1[i] != v2[i])
        {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}