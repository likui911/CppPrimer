#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class Vec
{
  public:
    typedef unsigned size_type;
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec();
    void push_back(const T &);
    size_type size() const { return first_free - elements; }
    size_type capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

  private:
    std::allocator<T> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
Vec<T>::Vec(const Vec<T> &vec)
{
    std::pair<T *, T *> newdata = alloc_n_copy(vec.begin(), vec.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &vec)
{
    std::pair<T *, T *> data = alloc_n_copy(vec.begin(), vec.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
void Vec<T>::push_back(const T &val)
{
    chk_n_alloc();
    alloc.construct(first_free++, val);
}

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    //allocate memory and return the first element
    T *data = alloc.allocate(e - b);
    //uninitialized_copy return the last element in the destination range
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::reallocate()
{
    //新的大小
    size_type newcapacity = size() ? 2 * size() : 1;
    T *newdata = alloc.allocate(newcapacity);

    auto dest = newdata;  //newdata作为新空间的开始
    auto elem = elements; //elements地址不可以改变

    for (size_type i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        //逆序销毁旧元素
        for (T *p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

////////testing code///////////
int main()
{
    Vec<int> vec;
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i * i);
    }
    //output result
    for (int i : vec)
    {
        cout << i << endl;
    }
    return 0;
}