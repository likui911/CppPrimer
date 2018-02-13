/*
Write a function that takes a reference to a container
and prints the elements in that container. Use the container’s size_type
and size members to control the loop that prints the elements.
*/
#include <vector>
#include <iostream>
using namespace std;

template <typename Container>
void Print(Container &val)
{
    for (typename Container::size_type i = 0; i != val.size(); ++i)
    {
        cout << val[i] << endl;
    }
}

template <typename Container>
void Print_1(Container &val)
{
    for (typename Container::iterator iter = val.begin(); iter != val.end(); ++iter)
    {
        cout << *iter << endl;
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Print(vec);
    Print_1(vec);
    return 0;
}