#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word, temp;
    while (cin >> word)
    {
        if (word == temp)
            break;

        else
            temp = word;
    }

    if (cin.eof()) //所有的单词读完，未遇到重复
        cout << "no word was repeated." << endl;
    else //连续的单词有重复
        cout << word << " occurs twice in succession." << endl;

    return 0;
}