#include "Worker.h"

Worker::Worker(bool li) : isLoggedIn(li) {} //po defaultu radnik nije ulogovan dok se ne izvrsi provjera

bool Worker::login(std::string username, std::string password) //uzima red po red iz dateteke koja sadrzi podatke o radnicima i pretrazuje da li za dati username i pass postoji takav radnik u datoteci
{
	std::ifstream file("Workers.txt");
	std::string line, usernameFile, passFile, temp; //usernameFile - username iz datoteke koji se poredi sa usernameom koji smo poslali kao argument funkcije , isto je i za passFile
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
					isLoggedIn = true;
					temp = line.substr(5, 16);
					temp.erase(remove_if(temp.begin(), temp.end(), static_cast<int(*)(int)>(isspace)), temp.end());
					this->name = temp;
					temp = line.substr(22, 16);
					temp.erase(remove_if(temp.begin(), temp.end(), static_cast<int(*)(int)>(isspace)), temp.end());
					this->surname = temp;
					this->id = std::stoi(line.substr(0, 1));
					return true;// uspjesna prijava
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

void Worker::bill()
{

}

void Worker::workersOnRoad()
{
	std::string cname,name1,surname1;
	int n;
	std::ofstream file("WorkersOnRoad.txt", std::ios::app);
	std::cout << "Unesite ime kompanije: " << std::endl;
	std::cin >> name1;
	file << name<<":"<<std::endl;
	std::cout << "Unesite broj radnika: " << std::endl; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Unesite ime radnika: "<<std::endl; std::cin >> name1;
		std::cout << "Unesite prezime radnika: " << std::endl; std::cin >> surname1;
		file << std::setw(10) << std::right << name1;
		file << std::setw(10) << std::right << surname1;
	}
}



void Worker::print()
{
	Human::print();
	std::cout << "is successfully registred.";
}
