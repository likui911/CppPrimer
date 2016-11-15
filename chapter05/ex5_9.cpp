#include <iostream>

using namespace std;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char c;
    while (cin >> c)
    {
        if (c == 'a')
            aCnt++;
        else if (c == 'e')
            eCnt++;
        else if (c == 'i')
            iCnt++;
        else if (c == 'o')
            oCnt++;
        else if (c == 'u')
            uCnt++;
    }

    cout << "a: " << aCnt << endl;
    cout << "e: " << eCnt << endl;
    cout << "i: " << iCnt << endl;
    cout << "o: " << oCnt << endl;
    cout << "u: " << uCnt << endl;
    return 0;
}