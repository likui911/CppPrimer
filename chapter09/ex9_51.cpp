/*
Write a class that has three unsigned members
representing year, month, and day. Write a constructor that takes a string
representing a date. Your constructor should handle a variety of date
formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
*/
#include <string>
#include <iostream>
#include "ex9_51.h"

using namespace std;

Date::Date(const string &s)
{
	if (s.find_first_of("123456789", 0) == 0)
	{
		auto idx = s.find_first_of("/");
		month = stoi(s.substr(0, idx));
		day = stoi(s.substr(idx + 1, s.find_first_of("/")));
		year = stoi(s.substr(s.find_last_of("/") + 1));
	}
	else if (s.find_first_of("JFMASOND") < s.find_first_of(","))
	{
		string m = s.substr(s.find_first_of("JFMASOND"), 3);
		if (m == "Jan")month = 1;
		if (m == "Feb")month = 2;
		if (m == "Mar")month = 3;
		if (m == "Apr")month = 4;
		if (m == "May")month = 5;
		if (m == "Jun")month = 6;
		if (m == "Jul")month = 7;
		if (m == "Aug")month = 8;
		if (m == "Sep")month = 9;
		if (m == "Oct")month = 10;
		if (m == "Nov")month = 11;
		if (m == "Dec")month = 12;
		day = stoi(s.substr(s.find_first_of("1234567890"),s.find_first_of(",")));
		year = stoi(s.substr(s.find_last_of(",")+1));
	}

}

void Date::print()
{
	cout << year << "-" << month << "-" << day << endl;
}

//testing
int main()
{
	Date a("January 1, 2016");
	a.print();
	Date b("3/9/2017");
	b.print();
	Date c("Apr 5, 2018");
	c.print();
	return 0;
}