#pragma once
#include "Human.h"
#include <fstream>
#include<tuple>
#include <ctime>
#include <algorithm>
class Worker: public Human
{
public:
	Worker();
	Worker(std::string, std::string);
	~Worker();
	bool login(std::string,std::string);
	void bill();
	void workersOnRoad(); 
 	void print();
private:
	void skipLinesInFile(std::ifstream&,int); //pomocna funkcija koja ce nam pomoci kod pozicioniranja u datoteci
};

