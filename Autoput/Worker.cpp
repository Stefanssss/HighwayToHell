#include "Worker.h"



Worker::Worker(){}

Worker::Worker(std::string name, std::string surname, std::string id) 
{ 
	this->name = name;
	this->surname = surname;
	this->id = id;
}


Worker::~Worker()
{
}

bool Worker::login(std::string username,std::string password)
{
	std::ofstream file("Workers.txt");
	if (file)
	{
			
	}
	return true;
	
}

void Worker::ticket(std::tuple<std::time_t, std::string>& location)
{
	std::make_tuple();
}

void Worker::insertDriver()
{

}

void Worker::print()
{
	Human::print();
	std::cout << "is successfully registred.";
}
