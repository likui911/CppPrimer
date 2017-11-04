/*
What changes would need to be made to StrBlobPtr to
create a class that can be used with a const StrBlob? Define a class
named ConstStrBlobPtr that can point to a const StrBlob.
*/
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class StrBlobPtr;

class StrBlob
{
  public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob()
        : data(std::make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() { data->pop_back(); }

    void push_back(const std::string &t)const { data->push_back(t); }
    void pop_back()const { data->pop_back(); }
    
    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
    // element access
    std::string &front() { return data->front(); }
    std::string &back() { return data->back(); }

  private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr
{
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
    std::string &deref() const;
    StrBlobPtr &incr(); // prefix version
  private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
    check(std::size_t, const std::string &) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // current position within the array
};

////////////////implement of class StrBlob///////////////////////

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i > data->size())
        throw out_of_range(msg);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const
{
    return StrBlobPtr(*this, data->size());
}

////////////////implement of class StrBlobPtr///////////////////////

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound strBlobPtr");

    if (i > ret->size())
        throw out_of_range(msg);

    return ret;
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(++curr, "dereference past end");
    return *this;
}

int main()
{
    const StrBlob blob;
    ifstream ifs("./chapter12/ex12_20.cpp");
    string s;
    while (getline(ifs, s))
    {
        blob.push_back(s);
    }

    for (StrBlobPtr ptr = blob.begin(); ptr != blob.end(); ptr.incr())
    {
        cout << ptr.deref() << endl;
    }
    return 0;
}