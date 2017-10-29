#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
template <typename T>
class StrBlob
{
  public:
    typedef typename vector<T>::size_type size_type;
    StrBlob() : data{make_shared<vector<T>>()} {}
    StrBlob(initializer_list<T> ls) : data{make_shared<vector<T>>(ls)} {}

    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }

    void push_back(const T &t);
    void pop_back();

    T &front();
    T &back();

    T &front() const;
    T &back() const;

  private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
void StrBlob<T>::push_back(const T &t)
{
    check(0, "push_back on empty StrBlob");
    data->push_back(t);
}

template <typename T>
void StrBlob<T>::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

template <typename T>
T &StrBlob<T>::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
T &StrBlob<T>::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
T &StrBlob<T>::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
T &StrBlob<T>::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
void StrBlob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

int main()
{
    const StrBlob<string> csb{"hello", "world", "kui"};
    StrBlob<string> sb{"hello", "world", "monkey"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "kui";
    std::cout << sb.front() << " " << sb.back() << std::endl;
    return 0;
}