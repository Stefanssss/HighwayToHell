#include "Driver.h"


Driver::Driver(std::string name, std::string surename,std::string category,std::string plates):category(category),plates(plates)
{
	Human(name, surename);
}
void Driver::insertDriver()
{
	std::string name1, surname1, temp, category, plates;
	std::cout << "Unesite ime vozaca:" << std::endl;
	std::cin >> name1; this->name = name1;
	std::cout << "Unesite prezime vozaca: " << std::endl;
	std::cin >> surname1; this->surname = surname1;
	std::cout << "Unesite kategoriju vozila: " << std::endl;
	std::cin >> category; this->category = category;
	std::cout << "Uesite registraciju vozila: " << std::endl;
	std::cin >> plates; this->plates = plates;
	//sada treba upisati u datoteku
}
void Driver::print()
{
	std::ofstream file("Drivers.txt", std::ios::app);
	file << std::setw(10) << std::left << name;
	file << std::setw(10) << std::left << surname;
	file << std::setw(10) << std::left << category;
	file << std::setw(10) << std::left << plates << std::endl;
}
Driver::~Driver()
{
}
