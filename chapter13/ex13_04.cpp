/*
Assuming Point is a class type with a public copy constructor, identify 
each use of the copy constructor in this program fragment:
    Point global;
    Point foo_bar(Point arg)
    {
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[ 4 ] = { local, *heap };
    return *heap;
    }
*/
#include <iostream>
using namespace std;

class Point
{
  public:
    Point(){};
    Point(const Point &) { cout << "copy construct" << endl; }
    Point &operator=(Point &p)
    {
        cout << "operator=" << endl;
        return *this;
    }
};

Point global;
Point foo_bar(Point arg)
{
    //2 copy construct
    Point local = arg, *heap = new Point(global);
    *heap = local;                //operator=
    Point pa[4] = {local, *heap}; //2 copy construct
    return *heap;                 //copy construct
}

int main()
{
    //copy construct
    foo_bar(global);
    return 0;
}