#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int strcompare(const char *str1, const char *str2)
{
    int length_1 = strlen(str1);
    int length_2 = strlen(str2);

    int range = length_1;

    if (range > length_2)
    {
        range = length_1;
    }

    for (int i = 0; i < range; ++i)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }
    if (length_1 == length_2)
    {
        return 0;
    }
    else if (length_1 > length_2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
    // use C-Style character strings.
    const char *cs1 = "english";
    const char *cs2 = "hanyu";

    auto result = strcompare(cs1, cs2);

    if (result == 0)
    {
        cout << "same string." << endl;
    }
    else if (result < 0)
    {
        cout << cs1 << " < " << cs2 << endl;
    }
    else
    {
        cout << cs1 << " > " << cs2 << endl;
    }

    return 0;
}