#include <vector>
using namespace std;

typedef vector<int>::iterator iter;

bool find(iter begin, iter end, int inc)
{
    while (begin != end)
    {
        if (*begin == inc)
            return true;
        begin++;
    }
    return false;
}

int main()
{

    return 0;
}