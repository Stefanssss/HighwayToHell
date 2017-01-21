#pragma once
#include<string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
class Human
{
public:
	Human();
	Human(std::string,std::string);
	virtual void print();
	~Human();
protected:
	std::string name, surname;
	
};

