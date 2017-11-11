/*
Exercise 13.44: Write a class named String that is a simplified version of
the library string class. Your class should have at least a default
constructor and a constructor that takes a pointer to a C-style string. Use
an allocator to allocate memory that your String class uses
*/
#include <string.h>
#include <iostream>

using namespace std;
class SString
{
  public:
    friend ostream &operator<<(ostream &os, const SString &str);
    SString() : data_(nullptr), len_(0) {}

    SString(const char *cstr)
        : SString(cstr, strlen(cstr)) {}

    SString(const char *cstr, size_t len)
        : data_(len > 0 ? new char[len + 1] : nullptr), len_(len)
    {
        if (len_)
        {
            memcpy(data_, cstr, len_);
            data_[len_] = '\0';
        }
    }

    SString(const SString &rhs)
        : SString(rhs.data_, rhs.len_) {}

    SString(SString &&rhs) noexcept
        : data_(rhs.data_), len_(rhs.len_)
    {
        rhs.data_ = nullptr;
        rhs.len_ = 0;
    }

    ~SString()
    {
        delete[] data_;
    }

    SString &operator=(const SString &rhs)
    {
        //先拷贝rhs的内容
        size_t len = rhs.len_;
        char *p = new char[len + 1];
        memcpy(p, rhs.data_, len + 1);
        //delete原有内容
        delete[] data_;

        data_ = p;
        len_ = len;
        return *this;
    }

    void swap(SString &rhs)
    {
        using std::swap;
        swap(len_, rhs.len_);
        swap(data_, rhs.data_);
    }

    const char *c_str() const noexcept
    {
        return data_ ? data_ : kEmpty;
    }

    size_t size() const noexcept
    {
        return len_;
    }

  private:
    char *data_;
    size_t len_;

    static const char kEmpty[];
};
ostream &operator<<(ostream &os, const SString &str)
{
    os << str.data_;
    return os;
}

int main()
{

    SString s("abcd", 4);
    SString s1("abcde");
    swap(s, s1);
    cout << s << endl;
    cout << s1 << endl;

    return 0;
}