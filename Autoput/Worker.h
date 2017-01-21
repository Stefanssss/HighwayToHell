#pragma once
#include <fstream>
#include <ctime>
#include <algorithm>
#include "Human.h"
#include "Driver.h"
#include "UsefulFunctions.h" //klasa koja sadrzi neke pomocne funckije

class Worker: public Human
{
public:
	Worker(bool=false);
	bool login(std::string,std::string);
	void bill(const Driver&);//izdavanje racuna vozacu tj. upisivanje u datoteku
	void workersOnRoad();//unosenje podataka o radnicma koji odrzavaju puteve
 	void print();
private:
	bool isLoggedIn;
	int id;
};

