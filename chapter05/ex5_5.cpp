#include <iostream>

using namespace std;

int main()
{
    cout << "Please input your score:" << endl;
    int score;
    cin >> score;
    int grade = score % 10;
    if (grade == 10)
    {
        cout << "A" << endl;
    }
    else if (grade == 9)
    {
        cout << "B" << endl;
    }
    else if (grade == 8)
    {
        cout << "C" << endl;
    }
    else if (grade == 7)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "E" << endl;
    }

    return 0;
}