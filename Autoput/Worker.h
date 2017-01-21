#pragma once
#include <fstream>
#include <ctime>
#include <algorithm>
#include "Human.h"
#include "UsefulFunctions.h" //klasa koja sadrzi neke pomocne funckije

class Worker: public Human
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

