#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    cout << v1.size() << endl; //0
    vector<int> v2(10);
    cout << v2.size() << endl; //10
    vector<int> v3(10, 42);
    cout << v3.size() << endl; //10
    vector<int> v4{10};
    cout << v4.size() << endl; //1
    vector<int> v5{10, 42};
    cout << v5.size() << endl; //2
    vector<string> v6{10};
    cout << v6.size() << endl; //10
    vector<string> v7{10, "hi"};
    cout << v7.size() << endl; //10
    return 0;
}