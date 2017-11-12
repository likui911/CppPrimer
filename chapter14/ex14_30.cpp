/*
Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class 
that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr 
must return const references because the data member in constStrBlobPtr points to a const vector
*/
#include <vector>
#include <memory>
#include <iostream >
using namespace std;
class StrBlobPtr;
class StrBlob
{
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

  public:
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il)
        : data(make_shared<vector<string>>(il)) {}

    StrBlob(const StrBlob &sb) : data(make_shared<vector<string>>(*sb.data)) {}
    StrBlob &operator=(const StrBlob &);
    StrBlob(StrBlob &&rhs) noexcept : data(std::move(rhs.data)) {}
    StrBlob &operator=(StrBlob &&) noexcept;
    StrBlobPtr begin();
    StrBlobPtr end();
    string &operator[](size_t n);
    const string &operator[](size_t n) const;
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void push_back(string &&s) { data->push_back(std::move(s)); }
    void pop_back() { data->pop_back(); }
    string &front() { return data->front(); }
    string &back() { return data->back(); }
    const string &front() const { return data->front(); }
    const string &back() const { return data->back(); }

  private:
    void check(size_type, const string &) const;
    shared_ptr<vector<string>> data;
};

class StrBlobPtr
{
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}
    //string &deref() const;
    string &operator*() const;
    string &operator[](size_t n);
    const string &operator[](size_t n) const;
    StrBlobPtr operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--();
    StrBlobPtr operator--(int);
    StrBlobPtr operator+(size_t n);
    StrBlobPtr operator-(size_t n);
    StrBlobPtr &operator+=(size_t n);
    StrBlobPtr &operator-=(size_t n);

  private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

StrBlob &StrBlob::operator=(const StrBlob &sb)
{
    data = make_shared<vector<string>>(*sb.data);
    return *this;
}

StrBlob &StrBlob::operator=(StrBlob &&sb) noexcept
{
    data = std::move(sb.data);
    sb.data = nullptr;
    return *this;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

string &StrBlob::operator[](size_t n)
{
    check(n, "n not in range");
    return data->operator[](n);
}

const string &StrBlob::operator[](size_t n) const
{
    check(n, "n not in range");
    return data->operator[](n);
}

//StrBlobPtr 实现
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw runtime_error("unbound shared_ptr");
    }
    if (i > ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

string &StrBlobPtr::operator[](size_t n)
{
    auto p = check(n, "derefernece n");
    return (*p)[n];
}

const string &StrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "derefernece n");
    return (*p)[n];
}

StrBlobPtr StrBlobPtr::operator++()
{
    check(curr + 1, "prefix increment");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--()
{
    check(curr - 1, "prefix decrement");
    --curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    check(curr + n, "addition");
    StrBlobPtr ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    check(curr - n, "subtration");
    StrBlobPtr ret = *this;
    ret.curr -= n;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    check(curr + n, "addition");
    curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    check(curr - n, "subtration");
    curr -= n;
    return *this;
}

int main()
{
    StrBlob sb{"11", "22", "33", "44"};
    auto iter = sb.begin();
    for (size_t i = 0; i < 4; ++i)
    {
        cout << *(iter + i) << endl;
    }
    return 0;
}