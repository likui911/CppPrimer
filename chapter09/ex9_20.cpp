#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> ls_i{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    deque<int> dq_even;
    deque<int> dq_odd;
    for (int i : ls_i)
    {
        if (i % 2 == 0)
        {
            dq_even.push_back(i);
        }
        else
        {
            dq_odd.push_back(i);
        }
    }
    return 0;
}