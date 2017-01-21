#include "Driver.h"


Driver::Driver(std::string name, std::string surename, std::string category, std::string plates) :category(category), plates(plates)
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
	if (file.good()) {
		file << std::setw(17) << std::left << const_cast<char*>(name.c_str()); //formatiran upis u datoteku (na kraju se string formatira u array of chars)
		file << std::setw(17) << std::left << const_cast<char*>(surname.c_str());
		file << std::setw(25) << std::left << const_cast<char*>(plates.c_str());
		file << std::setw(10) << std::left << const_cast<char*>(category.c_str()) << std::endl;
		file.close();
	}
	else
		std::cout << "Problem prilikom otvaranja datoteke koja sadrzi podatke o vozacima.";
}

