#include <string>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class BlobPtr;

template <typename T>
class Blob
{
  public:
    friend class BlobPtr<T>;

    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    Blob() : data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &val) { data->push_back(val); }
    void push_back(T &&val) { data->push_back(std::move(val)); }

    void pop_back()
    {
        check(0, "pop on empty Blob");
        data->pop_back();
    }

    T &back()
    {
        check(0, "back from empty Blob");
        return data->back();
    }

    T &operator[](size_type i)
    {
        check(i, "access out of range");
        return data->operator[](i);
    }

  private:
    std::shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
        {
            throw out_of_range(msg);
        }
    }
};

template <typename T>
class BlobPtr
{
  public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr &operator++()
    {
        check(curr, "increment past end");
        ++curr;
        return *this;
    }
    
    BlobPtr operator++(int)
    {
        BlobPtr ret = *this;
        ++*this; //invoke prefix operator++
        return ret;
    }

    BlobPtr &operator--()
    {
        check(0, "decrement past begin");
        --curr;
        return *this;
    }

    BlobPtr operator--(int)
    {
        BlobPtr ret = *this;
        --*this; //invoke prefix operator--
        return ret;
    }

  private:
    std::shared_ptr<vector<T>> check(std::size_t i, const string &msg) const
    {
        shared_ptr<vector<T>> ret = wptr.lock();
        if (!ret)
        {
            throw runtime_error("unbound BlobPtr");
        }
        if (i > ret.size())
        {
            throw out_of_range(msg);
        }
        return ret;
    }
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

int main()
{
    Blob<int> b{1, 2, 3, 4, 5};
    //BlobPtr使用了weak_ptr，使用过程中不增加Blob中shared_ptr的引用计数
    //每次使用wptr之前要先调用lock判断是Blob中的shared_ptr是否有效
    BlobPtr<int> ptr(b,0);

    return 0;
}