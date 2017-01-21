#pragma once //sadrzace neke korisne funkcije da bi se izbjeglo dupliranje koda
#include <iostream>
#include <fstream>
#include <string>

void skipLinesInFile(std::ifstream&, int); //pojasnjena napisana u cpp file-u

void printFile(std::istream &);