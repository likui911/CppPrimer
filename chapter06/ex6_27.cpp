#include <iostream>

using namespace std;

/*
*Write a function that takes an initializer_list<int> and
*produces the sum of the elements in the list.
*/
void print(initializer_list<string> sl)
{
    for (auto i = sl.begin(); i != sl.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    print({"hello", "world"});
    return 0;
}