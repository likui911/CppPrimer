/*
Define your own versions of the TextQuery and QueryResult classes and execute 
the runQueries function from § 12.3.1 (p.486).
*/
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

using namespace std;

using line_no = vector<string>::size_type;
class QueryResult;

class TextQuery
{
  public:
    TextQuery(ifstream &ifs);
    QueryResult query(const string &str) const;

  private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
  public:
    friend void print(ostream &ost, QueryResult &qr);
    QueryResult(string s, shared_ptr<set<line_no>> l, shared_ptr<vector<string>> f)
        : str{s}, ln{l}, file{f} {}

  private:
    string str;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> ln;
};

//implements
TextQuery::TextQuery(ifstream &ifs) : file(new vector<string>())
{
    string text;
    while (getline(ifs, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        stringstream line{text};
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines) //lines是nullptr时的处理
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    auto ret = wm.find(str);
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> no_data(new set<line_no>());
    if (ret == wm.end())
    {
        return QueryResult(str, no_data, file);
    }
    return QueryResult(str, ret->second, file);
}

void print(ostream &ost, QueryResult &qr)
{
    ost << "elements occurs " << qr.ln->size() << " times" << endl;
    for (auto i : *qr.ln)
    {
        ost << "\t"
            << "(line" << i + 1 << ") " << *(qr.file->begin() + i) << endl;
    }
}

int main()
{
    ifstream ifs{"./chapter09/99.txt"};
    TextQuery tq{ifs};
    string str;
    while (cin >> str)
    {
        QueryResult result = tq.query(str);
        print(cout, result);
    }

    return 0;
}