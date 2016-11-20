#include <iostream>

using namespace std;

// 交换指针，传入指针的引用
void swap(int *&a, int *&b)
{
    auto *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 33, b = 44;
    int *pa = &a;
    int *pb = &b;
    swap(pa, pb);
    cout << *pa << " " << *pb << endl;
    return 0;
}