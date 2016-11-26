#include <iostream>
#include <vector>

//declare a func return int with two int parameter
int func(int, int);

typedef decltype(func) *pFunc;

//declare a vector with the pFunc type
std::vector<pFunc> vFunc;