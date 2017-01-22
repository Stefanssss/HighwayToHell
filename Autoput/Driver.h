#pragma once
#include"Human.h"
class Driver: public Human
{
public:
	void insertDriver();
	void print();
private:
	std::string category, plates;
};

