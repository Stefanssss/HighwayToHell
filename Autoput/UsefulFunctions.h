#pragma once //sadrzace neke korisne funkcije da bi se izbjeglo dupliranje koda
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include<conio.h>
#include <vector>


void skipLinesInFile(std::ifstream&, int); //pojasnjena napisana u cpp file-u

void printFile(std::istream &);

void deleteBlanksInString(std::string &);

std::vector<std::string> readLocations(); //vraca vektor u koji su ucitani svi gradovi iz Gradovi.txt datoteke

std::string getPassword(); //funkcija koja se koristi za unos passworda gdje se u konzoli umjesto karatkera prikazuju *