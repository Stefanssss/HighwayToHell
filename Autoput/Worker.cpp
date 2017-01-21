#include "Worker.h"



Worker::Worker() {}

Worker::Worker(std::string name, std::string surname, std::string id)
{
	this->name = name;
	this->surname = surname;
	this->id = id;
}


Worker::~Worker()
{
}

bool Worker::login(std::string username, std::string password) //uzima red po red iz dateteke koja sadrzi podatke o radnicima i pretrazuje da li za dati username i pass postoji takav radnik u datoteci
{
	std::ifstream file("Workers.txt");
	std::string line, usernameFile, passFile; //usernameFile - username iz datoteke koji se poredi sa usernameom koji smo poslali kao argument funkcije , isto je i za passFile
	if (file.good())
	{
		skipLinesInFile(file, 2);
		while (getline(file, line))
		{
			usernameFile = line.substr(39, 12); //uzima username na osnovu pozicije u .txt datoteci
			usernameFile.erase(remove_if(usernameFile.begin(), usernameFile.end(), static_cast<int(*)(int)>(isspace)), usernameFile.end()); //izbacuje sva prazna mjesta u stringu (sve bjeline)
			if (usernameFile == username) //ako smo nasli username u bazi provjeravamo password , ako password nije ok napustamo provjeru
			{
				passFile = line.substr(55, 16);
				passFile.erase(remove_if(passFile.begin(), passFile.end(), static_cast<int(*)(int)>(isspace)), passFile.end());
				if (passFile == password)
				{
					std::cout << "Uspjesno prijavljivanje.";
					return true; // uspjesna prijava
				}
				else
					std::cout << "Pogresan password.";
			}
		}
		file.close();
	}
	else
		std::cout << "Greska pri otvaranju baze podataka koja sadrzi podatke o radnicima.";
	return false;

}

void skipLinesInFile(std::ifstream& dat, int n) //preskace odredjen broj linija u datoteci
{
	std::string temp;
	for (int i = 0;i < n;i++)
		getline(dat, temp);

}

void Worker::ticket(std::tuple<std::time_t, std::string>& location)
{
	std::make_tuple();
}

void Worker::insertDriver()
{
	std::string name1, surname1, temp, category,plates;
	std::cout << "Unesite ime vozaca:" << std::endl;
	std::cin >> name1;
	std::cout << "Unesite prezime vozaca: " << std::endl;
	std::cin >> surname1;
	std::cout << "Unesite kategoriju vozila: " << std::endl;
	std::cin >> category;
	std::cout << "Uesite registraciju vozila: " << std::endl;
	std::cin >> plates;
	//sada treba upisati u datoteku
}

void Worker::print()
{
	Human::print();
	std::cout << "is successfully registred.";
}
