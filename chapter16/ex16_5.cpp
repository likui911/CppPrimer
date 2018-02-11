#include <iostream>
using namespace std;

//接受一个数组引用，能处理任意大小、任意元素类型的数组
template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for (unsigned i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    print("good");
    print("hello world!");
    int arr[11]{1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 9};
    print(arr);
    return 0;
}