#pragma once
#include "Human.h"
#include <fstream>
#include<tuple>
#include <ctime>
class Worker: public Human
{
public:
	Worker();
	Worker(std::string, std::string, std::string);
	~Worker();
	bool login(std::string,std::string);
	void ticket(std::tuple<std::time_t, std::string>&);
	void insertDriver();
	void bill();
 	void print();
};

