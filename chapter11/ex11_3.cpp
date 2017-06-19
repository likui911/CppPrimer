/*
Write your own version of the word-counting program.
*/
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<string, int> word_counting;
    string word;
    while (cin >> word)
    {
        ++word_counting[word];
    }

    for (auto  elem : word_counting)
    {
        cout << elem.first << " occured " << elem.second << " times" << endl;
    }
    return 0;
}