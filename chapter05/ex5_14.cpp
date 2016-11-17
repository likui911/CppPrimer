#include <iostream>
#include <string>

using namespace std;

int main()
{
    string temp, preword = "", curword = "";
    unsigned preCnt = 0, curCnt = 1;
    while (cin >> temp)
    {
        if (temp != curword)
        {
            if (curCnt > preCnt)
            {
                preword = curword;
                preCnt = curCnt;
                curword = temp;
                curCnt = 1;
            }
            else
            {
                curword = temp;
                curCnt = 1;
            }
        }
        else
        {
            curCnt++;
        }
    }
    if (preCnt == 1)
    {
        cout << "no word was repeated." << endl;
    }
    cout << preword << endl;
    return 0;
}