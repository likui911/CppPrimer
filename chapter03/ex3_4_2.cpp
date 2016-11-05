#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.length() == b.length())
    {
        cout << "a.length==b.length"<<endl;
    }else{
        if(a.length()>=b.length())
        {
            cout<<"a longer than b !"<<endl;
        }else{
            cout<<"b longer than a !"<<endl;
        }
    }
    return 0;
}