/*
Write a function that returns a dynamically allocated
vector of ints. Pass that vector to another function that reads the standard
input to give values to the elements. Pass the vector to another function to
print the values that were read. Remember to delete the vector at the
appropriate time.
*/

#include <vector>
#include<iostream>
#include <memory>
using namespace std;

shared_ptr<vector<int>> dynamic_vector()
{
    return make_shared<vector<int>>();
}

void dynamic_processor(shared_ptr<vector<int>> vec_ptr)
{
    cout << vec_ptr.use_count();
    int i;
    while (cin >> i)
    {
        vec_ptr->push_back(i);
    }
}

void dynamic_print(shared_ptr<vector<int>> vec_ptr)
{
    for (auto i : *vec_ptr)
    {
        cout << i << endl;
    }
}

int main()
{
    shared_ptr<vector<int>> vec_ptr = dynamic_vector();
    dynamic_processor(vec_ptr);
    dynamic_print(vec_ptr);
    return 0;
}