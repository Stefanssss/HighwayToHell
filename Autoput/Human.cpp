#include "Human.h"



Human::Human(){}
Human::Human(std::string name,std::string surname):name(name),surname(surname)
{
}

void Human::print()
{
	std::cout << std::setw(10) << std::left << name;
	std::cout << std::setw(10) << std::left << surname;
}


Human::~Human()
{
}
