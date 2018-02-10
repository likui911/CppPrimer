class Base
{
  public:
    void pub_mem();

  protected:
    int prot_mem;

  private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f()
    {
        return prot_mem;
    }
    //priv_mem inaccesiable
    // char g()
    //{
    //  return priv_mem;
    //}
};

struct Pri_Derv : private Base
{
    //派生说明符不影响访问基类的成员
    int f()
    {
        return prot_mem;
    }
};

int main()
{
    Pub_Derv pub;
    Pri_Derv pri;
    pub.pub_mem();
    //派生说明符会影响派生类用户对基类成员的访问
    //pub_mem inaccessible
    //pri.pub_mem();

    Base *b = &pub;
    //只有当公有继承时才可以实现派生类向基类的转换（用户代码）
    //conversion to inaccessible Base
    //Base *b = &pri;
    return 0;
}