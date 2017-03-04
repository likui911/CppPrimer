#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string word;
    list<string> ls;
    while (cin >> word)
    {
        ls.push_back(word);
    }

    for (string w : ls)
    {
        cout << w << endl;
    }

    return 0;
}