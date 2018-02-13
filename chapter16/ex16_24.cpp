//Add a constructor that takes two iterators to your Blob template.
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Blob
{
  public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    Blob() : data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}
    //Add a constructor that takes two iterators
    template <typename InputIter>
    Blob(InputIter b, InputIter e): data(make_shared<vector<T>>(b, e)){}

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

int main()
{
    vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    Blob<int> blob(vec1.begin(), vec1.end());
    cout << blob.back() << endl;
    return 0;
}