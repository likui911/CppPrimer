#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word;
    vector<string> words;

    while (cin >> word)
    {
        words.push_back(word);
    }

    // change each word to upper case
    for (auto &w : words)
    {
        for (auto &c : w)
        {
            c = toupper(c);
        }
        cout << w << endl;
    }

    return 0;
}