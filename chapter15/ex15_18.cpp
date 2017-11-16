
class Base
{
  public:
    void pub_mem(); // public member
  protected:
    int prot_mem; // protected member
  private:
    char priv_mem; // private member
};
struct Pub_Derv : public Base
{
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    // char g() { return priv_mem; }
};
struct Priv_Derv : private Base
{
    // private derivation doesn't affect access in the derived class
    int f1() const { return prot_mem; }
};

struct Prot_Derv : protected Base
{
};

struct Derived_from_Public : public Pub_Derv
{
    // ok: Base::prot_mem remains protected in Pub_Derv
    int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_Derv
{
    // error: Base::prot_mem is private in Priv_Derv
    //int use_base() { return prot_mem; }
};
struct Derived_from_Protected : public Prot_Derv
{
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base *p = &d1; // d1 has type Pub_Derv
    p = &dd1;      // dd1 has type Derived_from_Public
    /*
    私有继承或受保护继承无法向基类转换
    */
    //p = &d2; // d2 has type Priv_Derv
    //p = &d3; // d3 has type Prot_Derv
    //p = &dd2; // dd2 has type Derived_from_Private
    //p = &dd3; // dd3 has type Derived_from_Protected
}