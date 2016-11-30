#include <iostream>

// declare two class type
class Y;
class X;

class X
{
    Y *theY = nullptr;
};

class Y
{
    X theX;
};