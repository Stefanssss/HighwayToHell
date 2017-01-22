#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "UsefulFunctions.h"
class RoadSection
{
public:
	RoadSection(std::string,std::string,int=0,bool=false);
	~RoadSection();
	void issuing();
	void print();
	void workable();
	double getDistance();//potrebno vracanja zbog izdavanja cijene
	bool operator==(const RoadSection&);
	bool isExistingInFile(); //pretrazuje da li u datoteci postoje dati gradovi i ako postoje upisuje ih u objekat
	void changeStatus(); //promjena statusa dionice puta(ako je bio u funkciji-prestaje biti, a ako nije bio u funkciji-postaje u funkciji)
private:
	std::string begin, end; //pocetak i kraj rute
	int distance; //rastojanje izmedju ulaza i izlaza
	bool is_working; //pokazuje da li je data dionica puta u funkciji
	void changeStatusInFile();
	int rb = -1; //broj reda u datoteci u kojem se nalaze dati gradovi (koristice se u nekim funkcijama clanicama)
};

