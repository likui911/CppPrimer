/*
Write versions of numbered and f corresponding to the previous three exercises and 
check whether you correctly predicted the output.
*/
#include <iostream>

using namespace std;

class numbered
{
  public:
    numbered()
    {
        static int unique = 10;
        mysn = unique++;
    }
    numbered(const numbered &num)
    {
        mysn = num.mysn + 1;
    }
    

    int mysn;
};

void f(const numbered &s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}