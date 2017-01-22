#pragma once
#include"Human.h"
class Driver: public Human
{
public:
	std::string getName() { return name; } 
	std::string getSurname() { return surname; }
	std::string getCategory() { return category; }
	std::string getplates() { return plates; }
	void insertDriver();
	void print();
private:
	std::string category, plates;
};

