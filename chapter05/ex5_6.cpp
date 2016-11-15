#include <iostream>

using namespace std;

int main()
{
    cout << "Please input your score:" << endl;
    int score;
    cin >> score;
    int grade = score % 10;
    
    grade == 10 ? cout << "A" : 
    grade == 9 ? cout << "B" : 
    grade == 8 ? cout << "C" : 
    grade == 7 ? cout << "D" : 
    grade == 6 ? cout << "E" : 
    cout << "F";

    return 0;
}