/*
 Exercise 13.39: Write your own version of StrVec, including versions of reserve, capacity (§ 9.4, p. 356), 
 and resize (§ 9.3.5, p. 352).
 Exercise 13.40: Add a constructor that takes an initializer_list<string>
 to your StrVec class.
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
    ~StrVec() { free(); };
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const string &);
    string *begin() const { return elements; }
    string *end() const { return first_free; }

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
    //Exercise 13.43 Rewrite the free member to use for_each and a lambda
    for_each(elements, first_free, [this](std::string &rhs) { alloc.destroy(&rhs); });
    alloc.deallocate(elements, cap - elements);
    // if (elements)
    // {
    //     for (auto p = first_free; p != elements;)
    //     {
    //         alloc.destroy(--p);
    //     }
    //     alloc.deallocate(elements, cap - elements);
    // }
}

void StrVec::push_back(const string &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

int main()
{

    {
        StrVec v{"1", "2", "3", "4", "5", "6", "7"};
    }

    // v.push_back("8");
    // for (auto s : v)
    // {
    //     cout << s << endl;
    // }
    return 0;
}