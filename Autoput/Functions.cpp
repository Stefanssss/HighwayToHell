#include "Functions.h"

void skipLinesInFile(std::ifstream& dat, int n) //preskace odredjen broj linija u datoteci
{
	std::string temp;
	for (int i = 0; i < n; i++)
		getline(dat, temp);
}