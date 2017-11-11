/*
Define a vector<String> and call push_back several times
on that vector. Run your program and see how often Strings are copied.
*/

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;
class String
{
  public:
    friend ostream &operator<<(ostream &os, const String &str);
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
        : String(rhs.data_, rhs.len_)
    {
        cout << "copy constructor" << endl;
    }

    String(String &&rhs) noexcept
        : data_(rhs.data_), len_(rhs.len_)
    {
        cout << "move constructor" << endl;
        rhs.data_ = nullptr;
        rhs.len_ = 0;
    }

    ~String()
    {
        delete[] data_;
    }

    String &operator=(const String &rhs)
    {
        cout << "assigment operator" << endl;
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
ostream &operator<<(ostream &os, const String &str)
{
    os << str.data_;
    return os;
}

int main()
{
    vector<String> vec;
    //vec.reserve(6);
    String s1("a"), s2("b"), s3("c"), s4("d");
    /*
        copy constructor
        copy constructor
        move constructor
        copy constructor
        move constructor
        move constructor
        copy constructor    
    */
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    vec.push_back(s4);

    return 0;
}