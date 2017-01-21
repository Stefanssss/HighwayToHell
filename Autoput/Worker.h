#pragma once
#include "Human.h"
#include "Functions.h" //klasa koja sadrzi neke pomocne funckije
#include <fstream>
#include<tuple>
#include <ctime>
#include <algorithm>
class Worker: public Human, public Functions
{
public:
	Worker(std::string=0, std::string=0);
	~Worker();
	bool login(std::string,std::string);
	void bill();
	void workersOnRoad(); 
 	void print();
};

