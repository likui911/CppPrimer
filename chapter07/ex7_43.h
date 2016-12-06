
#ifndef EX7_43_H
#define EX7_43_H

class NoDefault
{
public:
  NoDefault(int a) : init(a){};

private:
  int init;
};

class C
{
public:
  C() : ND_ins(0){}; //define the default constructer for C

private:
  NoDefault ND_ins;
};

#endif //EX7_43_H

int main()
{
  class A
  {
    int v;
  };
  A a;
  a.v = 3;
  return 0;
}