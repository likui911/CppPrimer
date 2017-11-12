/*
Write a class that tests whether two values are equal.Use that object and the library algorithms 
to write a program to replace all instances of a given value in a sequence.
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class IsEqual
{
  public:
    IsEqual(int v) : value(v) {}

    bool operator()(int a)
    {
        return a == value;
    }

  private:
    int value;
};

int main()
{
    IsEqual eq(3);
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    replace_if(vec.begin(), vec.end(), eq, 100);
    for (auto i : vec)
    {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}