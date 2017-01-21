#include "UsefulFunctions.h"

void skipLinesInFile(std::ifstream& dat, int n) //preskace odredjen broj linija u datoteci
{
	std::string temp;
	for (int i = 0; i < n; i++)
		getline(dat, temp);
}

void printFile(std::istream &file) //ispis kompletne datoteke
{
	std::string line;
	while (getline(file, line)) //uzima liniju po liniju i ispisuje dok se ne dodje do kraja datoteke
		std::cout << line << std::endl;
}