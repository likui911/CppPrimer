/*
Rewrite the biggies function from § 10.3.2 (p. 391) to
use function-object classes in place of lambdas.
*/
#include <vector>
#include <string>
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

class Cmp
{
  public:
    bool operator()(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
};

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words,
             vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), Cmp());
    auto wc = find_if(words.begin(), words.end(), IsMatch(sz));
    auto count = words.end() - wc;
    cout << count << " " << count
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    vector<string> vec{"1", "22", "33", "44", "666653456765432", "343234",
                       "23456543234543", "2222222222222", "222456765456787656"};
    biggies(vec, 5);
    return 0;
}