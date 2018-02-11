#include <string>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
class Blob
{
  public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &val) { data->push_back(val); }
    void push_back(T &&val) { data->push_back(std::move(val)); }

    void pop_back() { data->pop_back(); }

    T &back();
    T &operator[](size_type i);

  private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
class BlobPtr
{
  public:
    BlobPtr() : curr(0) {}
    BlobPtr(BlobPtr<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr &operator++(); // prefix operators
    BlobPtr &operator--();

  private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const string &msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

int main()
{
    return 0;
}