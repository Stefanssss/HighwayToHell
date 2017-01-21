#include "Human.h"



Human::Human(){}
Human::Human(std::string name,std::string surname,std::string id):name(name),surname(surname),id(id)
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
