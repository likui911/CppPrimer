#include <iostream>

using namespace std;

void print(const int i)
{
    cout << i << endl;
}

void print(const int arr[], size_t sz)
{
    for (int i = 0; i < sz; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg << " ";
        beg++;
    }
}

int main()
{
    int i = 0, j[2] = {1, 2};
    print(i);
    print(j, 2);
    print(begin(j), end(j));
    return 0;
}