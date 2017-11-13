/*
Write a class that tests whether the length of a given
string matches a given bound. Use that object to write a program to
report how many words in an input file are of sizes 1 through 10 inclusive.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class IsMatch
{
  public:
    IsMatch(int a, int b) : min(a), max(b) {}
    IsMatch(int a) : min(a), max(-1) {}

    bool operator()(const string &s) const
    {
        if (max == -1)
        {
            return min <= s.size();
        }
        return min <= s.size() && s.size() < max;
    }

  private:
    int min;
    int max;
};

int main()
{
    vector<string> vec{"1", "22", "33", "44", "666653456765432", "343234",
                       "23456543234543", "2222222222222", "222456765456787656"};
    cout << count_if(vec.begin(), vec.end(), IsMatch(1, 9)) << endl;
    cout<<count_if(vec.begin(),vec.end(),IsMatch(10))<<endl;
    return 0;
}