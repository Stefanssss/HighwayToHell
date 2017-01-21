#include "Human.h"



Human::Human() {}
Human::Human(std::string name, std::string surname) :name(name), surname(surname)
{
}

void Human::print()
{
	std::cout << "Ime:" << name << std::endl;
	std::cout << "Prezime:" << surname << std::endl;

}


Human::~Human()
{
}
