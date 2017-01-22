#include "Driver.h"

void Driver::insertDriver()
{
	std::string name1, surname1, temp, category, plates;
	std::cout << "   Unesite ime vozaca: ";
	std::cin >> name1; this->name = name1;
	std::cout << "   Unesite prezime vozaca: ";
	std::cin >> surname1; this->surname = surname1;
	std::cout << "KATEGORIJE VOZILA:" << std::endl;
	std::cout << "     IA   Motorna vozila s karakteristikama motocikla, motornog tricikla i cetverocikla." << std::endl;
	std::cout << "     I    Motorna vozila s dvije osovine, visine do 1, 30 m mjereno kod prve osovine, osim motornih vozila iz IIB." << std::endl;
	std::cout << "     II   A) Motorna vozila s tri ili vise osovina, visine do 1, 30 m mjereno kod prve osovine." << std::endl;
	std::cout << "          B) Motorna vozila s dvije osovine visine vece od 1, 90 m, cija najveca dopustena masa ne prelazi 3500 kg." << std::endl;
	std::cout << "     III  Motorna vozila s dvije ili tri osovine, visine vece od 1, 30 m mjereno kod prve osovine," << std::endl;
	std::cout << "                najvece dopustene mase iznad 3500 kg, ukljucujuci motorna vozila iz IIB kategorije s prikolicom." << std::endl;
	std::cout << "     IV   Motorna vozila s cetiri ili vise osovina, visine vece od 1, 30 m mjereno kod prve osovine," << std::endl;
	std::cout << "                najvece dopustene mase iznad 3500 kg." << std::endl;
	do {
		std::cout << "   Unesite kategoriju vozila: ";
		std::cin >> category; this->category = category;
		if (category != "I"&& category != "IA" && category != "IIA" && category != "IIB" && category != "III" && category != "IV" && category != "II")
			std::cout << "     Pogresan unos kategorije, molimo Vas unesite ponovo." << std::endl << std::endl;
	} while (category != "I"&& category != "IA" && category != "IIA" && category != "IIB" && category != "III" && category != "IV" && category!="II");
	std::cout << "   Uesite registraciju vozila: ";
	std::cin >> plates; this->plates = plates;
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

