/*
Write a program to process a vector<string>s whose
elements represent integral values. Produce the sum of all the elements in
that vector. Change the program so that it sums of strings that represent
floating-point values.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void func_int()
{
	vector<string> vec_i{ "1","11","111","6","11" };
	int sum_i = 0;
	for (const string &s : vec_i)
	{
		sum_i+=stoi(s);
	}
	cout << sum_i << endl;
}

void func_float()
{
	vector<string> vec_f{"1.1","2.2","3.3","4.4","5.5","6.6","7.7"};
	float sum_f = 0.0;
	for (const string &s : vec_f)
	{
		sum_f += stof(s);
	}
	cout << sum_f << endl;
}

//testing
//int main()
//{
//	func_int();
//	func_float();
//	return 0;
//}