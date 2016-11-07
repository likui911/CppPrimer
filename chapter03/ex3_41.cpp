#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec(begin(arr), end(arr));

    for (int i : ivec)
    {
        cout << i << endl;
    }
    return 0;
}