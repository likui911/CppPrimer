#include <iostream>

using namespace std;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0,
             tabCnt = 0, lineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    char pre_c = ' ';
    char c;
    while (cin.get(c))
    {
        switch (c)
        {

        case 'a':
        case 'A':
            aCnt++;
            break;
        case 'e':
        case 'E':
            eCnt++;
            break;
        case 'i':
            if (pre_c == 'f')
            {
                fiCnt++;
                //break; 这里不清楚，当前一个字符为f时iCnt是否还要计算
            }
        case 'I':
            iCnt++;
            break;
        case 'o':
        case 'O':
            oCnt++;
            break;
        case 'u':
        case 'U':
            uCnt++;
            break;
        case ' ':
            blankCnt++;
            break;
        case '\t':
            tabCnt++;
            break;
        case '\n':
            lineCnt++;
            break;
        case 'f':
            if (pre_c == 'f')
                ffCnt++;
        case 'l':
            if (pre_c == 'f')
                flCnt++;
            break;
        }
        pre_c = c;
    }

    cout << "a: " << aCnt << endl;
    cout << "e: " << eCnt << endl;
    cout << "i: " << iCnt << endl;
    cout << "o: " << oCnt << endl;
    cout << "u: " << uCnt << endl;
    cout << "blank: " << blankCnt << endl;
    cout << "tab: " << tabCnt << endl;
    cout << "newline: " << lineCnt << endl;
    cout << "ffCnt: " << ffCnt << endl;
    cout << "flCnt: " << flCnt << endl;
    cout << "fiCnt: " << fiCnt << endl;
    return 0;
}