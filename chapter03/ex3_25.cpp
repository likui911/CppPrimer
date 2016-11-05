#include <iostream>
#include <vector>
#include <string>

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
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        for (auto j = (*i).begin(); j != (*i).end(); ++j)
        {
            *j = toupper(*j);
        }
        cout << *i << endl;
    }

    return 0;
}