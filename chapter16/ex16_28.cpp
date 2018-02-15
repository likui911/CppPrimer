#include <utility>
#include <functional>
/*
编写你自己版本的shared_ptr和unique_ptr
*/
template <typename T>
class default_delete
{
  public:
    default_delete() {}

    void operator()(T *p)
    {
        delete p;
    }
};

//////////////////shared_ptr implements///////////////////////
template <typename T, typename D = default_delete<T>()>
class shared_ptr
{
  public:
    typedef T element_type;

    constexpr shared_ptr() noexcept = default;

    shared_ptr(T *p, D del)
        : ptr(p), refCount(new std::size_t(1)), deleter(del)
    {
    }

    shared_ptr(const shared_ptr &x) noexcept;

    shared_ptr(shared_ptr &&x) noexcept;

    ~shared_ptr()
    {
        decrement_delete();
    }

    shared_ptr &operator=(const shared_ptr &x) noexcept;

    shared_ptr &operator=(shared_ptr &&x) noexcept;

    void swap(shared_ptr &x) noexcept;

    void reset() noexcept;

    element_type *get() const noexcept;

    element_type &operator*() const noexcept;

    element_type *operator->() const noexcept;

    long int use_count() const noexcept;

    bool unique() const noexcept;

    explicit operator bool() const noexcept;

  private:
    T *ptr;
    std::size_t *refCount;
    D deleter;
    //decrement the refCount,if refCount goes to zero ,delete ptr and refCount
    void decrement_delete();
};

template <class T>
void swap(shared_ptr<T> &x, shared_ptr<T> &y) noexcept;

template <class T, class... Args>
shared_ptr<T> make_shared(Args &&... args);

//////////////////unique_ptr implements///////////////////////

//forward declarations for friendship
template <typename T, typename D>
class unique_ptr;

template <class T, class D>
void swap(unique_ptr<T, D> &x, unique_ptr<T, D> &y) noexcept;

template <typename T, typename D = default_delete<T>>
class unique_ptr
{
  public:
    friend void swap<T, D>(unique_ptr<T, D> &x, unique_ptr<T, D> &y) noexcept;

    typedef T element_type;
    typedef T *pointer;
    typedef D deleter_type;

    constexpr unique_ptr() noexcept = default;
    explicit unique_ptr(pointer p) noexcept : ptr(p)
    {
    }
    unique_ptr(const unique_ptr &) = delete;

    ~unique_ptr()
    {
        deleter(ptr);
    }
    unique_ptr &operator=(unique_ptr &&x) noexcept;
    unique_ptr &operator=(const unique_ptr &) = delete;
    pointer get() const noexcept;
    deleter_type &get_deleter() noexcept;
    const deleter_type &get_deleter() const noexcept;
    explicit operator bool() const noexcept;
    pointer release() noexcept;
    void reset() noexcept;
    void reset(pointer p) noexcept;
    void swap(unique_ptr &rhs) noexcept;

    element_type &operator*() const;
    pointer operator->() const noexcept;

  private:
    T *ptr = nullptr;
    D deleter = D();
};

template <typename T, typename D>
inline unique_ptr<T, D> &unique_ptr<T, D>::operator=(unique_ptr &&rhs) noexcept
{
    if (this->ptr != rhs.ptr)
    {
        deleter(ptr);
        ptr = nullptr;
        swap(*this, rhs);
    }
    return *this;
}

//Notice that a call to this function does not make unique_ptr release ownership of the pointer
template <typename T, typename D>
inline typename unique_ptr<T, D>::pointer unique_ptr<T, D>::get() const noexcept
{
    return this->ptr;
}

template <typename T, typename D>
inline typename unique_ptr<T, D>::deleter_type &unique_ptr<T, D>::get_deleter() noexcept
{
    return deleter;
}

template <typename T, typename D>
inline const typename unique_ptr<T, D>::deleter_type &unique_ptr<T, D>::get_deleter() const noexcept
{
    return deleter;
}

template <typename T, typename D>
unique_ptr<T, D>::operator bool() const noexcept
{
    return ptr != nullptr;
}

template <typename T, typename D>
void unique_ptr<T, D>::reset() noexcept
{
    deleter(ptr);
    ptr = nullptr;
}

template <typename T, typename D>
void unique_ptr<T, D>::reset(typename unique_ptr<T, D>::pointer p) noexcept
{
    deleter(ptr);
    ptr = p;
}
template <typename T, typename D>
void unique_ptr<T, D>::swap(unique_ptr &rhs) noexcept
{
    std::swap(this->ptr, rhs.ptr);
    std::swap(this->deleter, rhs.deleter);
}

template <typename T, typename D>
typename unique_ptr<T, D>::element_type &unique_ptr<T, D>::operator*() const
{
    return *ptr;
}

template <typename T, typename D>
typename unique_ptr<T, D>::pointer unique_ptr<T, D>::operator->() const noexcept
{
    return ptr;
}

template <class T, class D>
void swap(unique_ptr<T, D> &lhs, unique_ptr<T, D> &rhs) noexcept
{
    std::swap(lhs.ptr, rhs.ptr);
    std::swap(lhs.deleter, rhs.deleter);
}

////////////////////test code///////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace std;

int main()
{
    {
        string *str = new string("abcd");
        {
            unique_ptr<string> ptr(str);
            cout << ptr->c_str() << endl;
        }
    }

    return 0;
}