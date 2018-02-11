#include <iostream>
using namespace std;

//返回任意数组的大小
template <typename T, unsigned N>
constexpr unsigned arrsize(const T (&)[N])
{
    return N;
}

int main()
{
    cout << arrsize("hello world!") << endl;
    return 0;
}