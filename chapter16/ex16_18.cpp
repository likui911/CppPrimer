
//correct ex16_18 declares
template <typename T, typename U, typename V>
void f1(T, U, V);

template <typename T>
T f2(int &t);

template <typename T>
T inline foo(T, unsigned int *);

template <typename T>
void f4(T, T);

//f5的返回值和参数都是模板实参类型
//屏蔽了typedef的声明
typedef char Ctype;
template <typename Ctype>
Ctype f5(Ctype a)
{
    return a;
}

int main()
{
    auto c=f5(44);
    return 0;
}