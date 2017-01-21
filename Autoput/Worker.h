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
	Worker(bool=false);
	bool login(std::string,std::string);
	void bill();
	void workersOnRoad(); 
 	void print();
private:
	bool isLoggedIn;
	int id;
};

