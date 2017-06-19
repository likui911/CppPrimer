/*
Extend your program to ignore case and punctuation. For
example, “example.” “example,” and “Example” should all increment the
same counter.
*/
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    map<string, size_t> word_counting;
    string word;
    while (cin >> word)
    {
        for (char &ch : word)
            ch = tolower(ch);
        //remove_if重排了word，没有大小，
        auto iter = remove_if(word.begin(), word.end(), ispunct);
        //截取word
        word.erase(iter, word.end());
        ++word_counting[word];
    }
    for (auto elem : word_counting)
    {
        cout << elem.first << " occured " << elem.second << " times" << endl;
    }
    return 0;
}