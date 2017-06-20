/*
Write a program that stores the excluded words in a
vector instead of in a set. What are the advantages to using a set?
*/
#include <set>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void fun_using_set()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (auto &elem : word_count)
    {
        cout << elem.first << " - " << elem.second << endl;
    }
}

void fun_using_vector()
{
    map<string, size_t> word_count;
    vector<string> exclude = {"The", "But", "And", "Or", "An", "A",
                              "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
    {
        //当exclude数据量比较大时，查询效率非常低
        if (std::find(exclude.begin(), exclude.end(), word) == exclude.end())
        {
            ++word_count[word];
        }
    }

    for (auto &elem : word_count)
    {
        cout << elem.first << " - " << elem.second << endl;
    }
}

int main()
{
    fun_using_vector();
    return 0;
}