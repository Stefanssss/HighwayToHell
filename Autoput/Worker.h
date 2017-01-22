#pragma once
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include "Human.h"
#include "Driver.h"
#include "UsefulFunctions.h" //klasa koja sadrzi neke pomocne funckije

class Worker: public Human
{
public:
	Worker(bool=false);
	bool login(std::string,std::string);
	void bill(const Driver&);//izdavanje racuna vozacu tj. upisivanje u datoteku
	void workersOnRoad(const std::string&,const std::string&);//unosenje podataka o radnicma koji odrzavaju puteve,stringovi su gradovi izmejdu kojih se vrsi odrzavanje 
	void workersOnRoadDelete(const std::string&, const std::string&); //brisanje kompanije i radnika koji odrzavaju odredjenu dionicu iz datoteke
	void print();
private:
	bool isLoggedIn;
	int id;
};

