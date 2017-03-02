#include <deque>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
    deque<int> di{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<deque<int>> ld{di};
    return 0;
}