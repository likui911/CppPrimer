#include <vector>

using namespace std;

/*
 *Show an example of each of the six ways to create and
 *initialize a vector.
 */

int main()
{
    vector<int> vec_1;
    vector<int> vec_2(10);
    vector<int> vec_3(10, 0);
    vector<int> vec_4 = {1, 2, 3};
    vector<int> vec_5(vec_4);
    vector<int> vec6(vec_4.begin(), vec_4.end());
    return 0;
}