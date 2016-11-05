#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    for (auto c : line)
    {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    return 0;
}