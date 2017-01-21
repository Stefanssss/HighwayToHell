#pragma once
#include<string>
#include <iostream>
#include <iomanip>
class Human
{
public:
	Human();
	Human(std::string,std::string,std::string);
	virtual void print();
	~Human();
protected:
	std::string name, surname,id;
	
};

