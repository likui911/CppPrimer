#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word, prev_word;
    while (cin >> word)
    {
        //首字母非大写，跳过
        if (!isupper(word[0]))
            continue;

        if (word == prev_word)
            break;
        else
            prev_word = word;
    }
    if (cin.eof())
        cout << "no word was repeated.no" << endl;
    else
        cout << word << " occurs twice in succession." << endl;
        
    return 0;
}