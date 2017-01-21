#pragma once
#include"Human.h"
class Driver: public Human
{
public:
	Driver(std::string=0,std::string=0,std::string=0,std::string=0);
	void insertDriver();
	void print();
private:
	std::string category, plates;
};

