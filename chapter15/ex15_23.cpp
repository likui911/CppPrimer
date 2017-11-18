/*
Exercise 15.23: Assuming class D1 on page 620 had intended to override
its inherited fcn function, how would you fix that class? Assuming you fixed
the class so that fcn matched the definition in Base, how would the calls in
that section be resolved?
*/
class Base
{
  public:
    virtual int fcn();
};
class D1 : public Base
{
  public:
    int fcn() override; //override virtual fcn from Base
    int fcn(int);       // parameter list differs from fcn in Base
    virtual void f2();  // new virtual function that does not exist in Base
};
class D2 : public D1
{
  public:
    int fcn(int);       // nonvirtual function hides D1::fcn(int)
    int fcn();          // overrides virtual fcn from Base
    void f2() override; // overrides virtual f2 from D1
};