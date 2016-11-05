#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alphabet = "abcdefgxyz";

    for (auto &c : alphabet)
    {
        c = 'x';
    }

    cout << alphabet << endl;
    return 0;
}