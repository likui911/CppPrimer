#include <iostream>

using namespace std;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int blankCnt = 0, tabCnt = 0, lineCnt = 0;
    char c;
    while (cin.get(c))
    {
        if (c == 'a' || c == 'A')
            aCnt++;
        else if (c == 'e' || c == 'E')
            eCnt++;
        else if (c == 'i' || c == 'I')
            iCnt++;
        else if (c == 'o' || c == 'O')
            oCnt++;
        else if (c == 'u' || c == 'U')
            uCnt++;
        else if (c == '\t')
            tabCnt++;
        else if (c == ' ')
            blankCnt++;
        else if (c == '\n')
            lineCnt++;
    }

    cout << "a: " << aCnt << endl;
    cout << "e: " << eCnt << endl;
    cout << "i: " << iCnt << endl;
    cout << "o: " << oCnt << endl;
    cout << "u: " << uCnt << endl;
    cout << "blank: " << blankCnt << endl;
    cout << "tab: " << tabCnt << endl;
    cout << "newline: " << lineCnt << endl;
    return 0;
}