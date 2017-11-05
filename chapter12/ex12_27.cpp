/*
The TextQuery and QueryResult classes use only
capabilities that we have already covered. Without looking ahead, write
your own versions of these classes.
*/
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery
{
  public:
    TextQuery(ifstream &ifs);
    QueryResult query(const string &str) const;

  private:
    vector<string> file;
    map<string, set<line_no>> wm;
};

class QueryResult
{
  public:
    QueryResult(const vector<string> &f, const set<line_no> &l)
        : file{f}, ln{l} {}
    void print();

  private:
    vector<string> file;
    set<line_no> ln;
};

/////////////////implements//////////////////////
TextQuery::TextQuery(ifstream &ifs)
{
    string s;
    while (getline(ifs, s))
    {
        //将数据行存入file变量中
        file.push_back(s);
    }
    //遍历file，初始化wm
    for (int i = 0; i < file.size(); ++i)
    {
        stringstream ss{file[i]};
        string temp;
        while (ss >> temp)
        {
            wm[temp].insert(i);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    //构造一个QueryResult对象
    return QueryResult(file, wm.at(str));
}

void QueryResult::print()
{
    cout << "elements occurs " << ln.size() << " times" << endl;
    for (auto i : ln)
    {
        cout << "\t"
             << "(line" << i + 1 << ") " << file[i] << endl;
    }
}

int main()
{
    ifstream ifs{"./chapter09/99.txt"};
    TextQuery tq{ifs};
    tq.query("letter").print();
    return 0;
}