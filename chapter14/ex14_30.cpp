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
class ConstStrBlobPtr;

class StrBlob
{
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

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
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
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
    StrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}
    string &operator*() const;
    //operator->必须返回类的指针或者是重载了operator->的对象
    string *operator->() const { return &operator*(); }
    string &operator[](size_t n);
    const string &operator[](size_t n) const;
    StrBlobPtr &operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr &operator--();
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

class ConstStrBlobPtr
{
  public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}
    //constStrBlobPtr与StrBlobPtr的区别是
    //该类型只能用于读取容器内的元素，但不能改变其值。
    const string &operator*() const;
    const string *operator->() const { return &operator*(); }
    const string &operator[](size_t n) const;
    ConstStrBlobPtr operator+(size_t n);
    ConstStrBlobPtr operator-(size_t n);
    ConstStrBlobPtr &operator+=(size_t n);
    ConstStrBlobPtr &operator-=(size_t n);
    ConstStrBlobPtr &operator++();
    ConstStrBlobPtr &operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);

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

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this, 0);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
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

StrBlobPtr &StrBlobPtr::operator++()
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

StrBlobPtr &StrBlobPtr::operator--()
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

//ConstStrBlobPtr实现
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
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

const string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const string &ConstStrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "dereference n");
    return (*p)[n];
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n)
{
    check(curr + n, "operator+");
    ConstStrBlobPtr ret = *this;
    ret.curr += n;
    return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n)
{
    check(curr - n, "operator-");
    ConstStrBlobPtr ret = *this;
    ret.curr -= n;
    return ret;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator+=(size_t n)
{
    check(curr + n, "operator+=");
    curr += n;
    return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator-=(size_t n)
{
    check(curr + n, "operator-=");
    curr -= n;
    return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator++()
{
    check(curr + 1, "operator++");
    ++curr;
    return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator--()
{
    check(curr - 1, "operator++");
    --curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    check(curr + 1, "operator++");
    ConstStrBlobPtr ret = *this;
    ++curr;
    return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    check(curr - 1, "operator++");
    ConstStrBlobPtr ret = *this;
    --curr;
    return ret;
}

int main()
{
    const StrBlob sb{"1", "22", "333", "4444"};
    auto iter = sb.begin();
    for (size_t i = 0; i < 4; ++i)
    {
        cout << iter->size() << "\t";
        cout << *(iter + i) << endl;
    }
    return 0;
}