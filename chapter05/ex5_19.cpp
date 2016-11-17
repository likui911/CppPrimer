#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "input two strings: " << endl;
    string str1 = " ", str2 = " ";
    do
    {
        if (str1 == str2)
            continue;
        string less = str1.size() < str2.size() ? str1 : str2;
        string longer = str1.size() < str2.size() ? str2 : str1;

        cout << less << " less than " << longer << endl;

    } while (cin >> str1 >> str2);

    return 0;
}