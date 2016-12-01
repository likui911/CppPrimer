#include <iostream>
#include <string>
/*
Explain the following code, indicating which definition of
Type or initVal is used for each use of those names. Say how you would
fix any errors.
*/
typedef std::string Type; //Type 1

Type initVal();//Type 1
class Exercise
{
  public:
    typedef double Type; //Type 2
    //return type and parameter type is Type2
    Type setVal(Type);
    Type initVal();

  private:
    int val;
};

/*
//return type is Type 1
//parameter type is Type 2
Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val; //return Type is int
}
*/

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val; //return Type is int
}