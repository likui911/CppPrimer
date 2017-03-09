#include <string>
#include <iostream>

#ifndef EX9_51_H
#define EX9_51_H

class Date {

	public:
		Date(const std::string &str);
		void print();
	private:
		unsigned year;
		unsigned month;
		unsigned day;
};
#endif