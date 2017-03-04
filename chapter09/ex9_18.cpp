#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    string word;
    deque<string> dqs;
    while (cin >> word)
    {
        dqs.push_back(word);
    }

    for (string w : dqs)
    {
        cout << w << endl;
    }

    return 0;
}