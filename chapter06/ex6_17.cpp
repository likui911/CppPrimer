#include <iostream>
#include <string>

using namespace std;

bool hasCaptial(const string &word)
{
    for (auto c : word)
    {
        if (isupper(c) == true)
        {
            return true;
        }
    }
    return false;
}

void makeLowercase(string &word)
{
    for (auto &c : word)
    {
        if (!islower(c))
            c = tolower(c);
    }
}

int main()
{
    string test = "Write a function";
    if (hasCaptial(test))
    {
        cout << "words contains at least one captial." << endl;
        makeLowercase(test);
    }
    cout << test << endl;

    return 0;
}