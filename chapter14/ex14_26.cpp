/*
 Define subscript operators for your StrVec, String,StrBlob, and StrBlobPtr classes.
*/
#include <string>
#include <memory>
#include <initializer_list>
#include <iostream>
#include <algorithm>

using namespace std;

class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string> il);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &rhs);
    StrVec &operator=(initializer_list<string> il);
    ~StrVec() { free(); };
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const string &);
    string &operator[](size_t n) { return *(elements + n); }
    const string &operator[](size_t n) const { return *(elements + n); }
    string *begin() { return elements; }
    string *end() { return first_free; }
    const string *begin() const { return elements; }
    const string *end() const { return first_free; }

  private:
    allocator<string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void reallocate();
    void free();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

StrVec::StrVec(initializer_list<string> il)
{
    auto newData = alloc_n_copy(il.begin(), il.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::StrVec(const StrVec &rhs)
{
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    auto newData = alloc_n_copy(&*il.begin(), &*il.end());
    free();
    elements = newData.first;
    first_free = cap = newData.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newCapcity = size() ? 2 * size() : 8;
    string *newData = alloc.allocate(newCapcity);
    string *dest = newData;
    string *elem = elements;
    for (size_t i = 0; i < size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapcity;
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    string *data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    for_each(elements, first_free, [this](std::string &rhs) { alloc.destroy(&rhs); });
    alloc.deallocate(elements, cap - elements);
}

void StrVec::push_back(const string &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

int main()
{
    StrVec vec{"1", "2", "2"};
    cout << vec[0] << endl;
    cout << vec[2] << endl;
    //cout << vec[3] << endl;
    return 0;
}
