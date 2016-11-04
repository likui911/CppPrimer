#include <iostream>

using namespace std;

int main()
{
    int *p = nullptr;
    int a = 1024;
    //change the value of a pointer
    p = &a; 

    //change the value to which the pointer points
    *p = 2048;
    cout<<a<<endl;

    return 0;
}