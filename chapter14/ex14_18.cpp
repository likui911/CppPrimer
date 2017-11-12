/*
 Define relational operators for your StrBlob, StrBlobPtr,StrVec, and String classes.
*/
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;
class String
{
  public:
    //relational operators
    friend bool operator<(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend bool operator==(const String &, const String &);

    String() : data_(nullptr), len_(0) {}

    String(const char *cstr)
        : String(cstr, strlen(cstr)) {}

    String(const char *cstr, size_t len)
        : data_(len > 0 ? new char[len + 1] : nullptr), len_(len)
    {
        if (len_)
        {
            memcpy(data_, cstr, len_);
            data_[len_] = '\0';
        }
    }

    String(const String &rhs)
        : String(rhs.data_, rhs.len_) {}

    String(String &&rhs) noexcept
        : data_(rhs.data_), len_(rhs.len_)
    {
        rhs.data_ = nullptr;
        rhs.len_ = 0;
    }

    ~String()
    {
        delete[] data_;
    }

    String &operator=(const String &rhs)
    {
        if (&rhs == this)
            return *this;
        size_t len = rhs.len_;
        char *p = new char[len + 1];
        memcpy(p, rhs.data_, len + 1);
        delete[] data_;

        data_ = p;
        len_ = len;
        return *this;
    }

    void swap(String &rhs)
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
bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data_, rhs.data_) < 0;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data_, rhs.data_) <= 0;
}

bool operator>(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data_, rhs.data_) > 0;
}

bool operator>=(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data_, rhs.data_) >= 0;
}
bool operator==(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data_, rhs.data_) == 0;
}

int main()
{
    String a("a");
    String b("b");
    if (a > b)
        cout << "a>b" << endl;
    else
        cout << "a<b" << endl;

    return 0;
}