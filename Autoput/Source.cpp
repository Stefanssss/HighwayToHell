#include "Driver.h"
#include "Worker.h"
#include "RoadSection.h"
#include <vector>

int main()
{

	Worker worker1;
	int i = 0;
	do
	{
		//system("CLS");
		std::string username, password;
		std::cout << "Molimo radnika da unese podatke:" << std::endl;
		std::cout << "	Unesite korisnicko ime: ";
		std::cin >> username;
		std::cout << "	Unesite password: ";
		std::cin >> password;

		if (worker1.login(username, password))
		{
			std::cout << std::endl;
			worker1.print();
			i = 1;
		}
		else
			std::cout << "Greske pri unosu podataka, unesite podatke ponovo." << std::endl;
	} while (i == 0);
	//system("CLS");
	int temp;
	do
	{
		std::cout << "\nIzaberite funkciju:" << std::endl;
		std::cout << "Za izdavanje racuna unesite 1" << std::endl;
		std::cout << "Promjena statusa odredjene dionice 2" << std::endl;
		std::cout << "Za prikaz o stanju na dionicam unesite 3" << std::endl;
		std::cout << "Za evidenciju o izvodjacima radova unesite 4" << std::endl;
		std::cin >> temp;
		if (temp == 1)
		{
			Driver dr;
			dr.insertDriver();
			dr.print();
			worker1.bill(dr);
		}
		else if (temp == 2)
		{
			std::string loc1, loc2;
			bool flag = 0;
			do {
				std::cout << "Unesite pocetnu lokaciju: " << std::endl;
				std::cin >> loc1;
				std::cout << "Unesite krajnju lokaciju: " << std::endl;
				std::cin >> loc2;
				RoadSection road(loc1, loc2); //konstruktor
				if (flag = road.isExistingInFile()) //provjera da li gradovi postoje u datoteci
					road.changeStatus(); //mijenja status dionice
				else
					std::cout << "Jedna ili obe lokacije ne postoje u datoteci, molimo unesite ponovo.";
			} while (flag == false);

		}
		else if (temp == 3)
		{
			std::ifstream dat("Gradovi.txt");
			printFile(dat);
			//ucitavanje o stanju puteva iz datoteke i ispisivanje na standardni izlaz 
		}
		else if (temp == 4)
		{
			//evidencija o izvodjacima radova
			//  worker1.workersOnRoad();
		}
		if (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0)
		{
			std::cout << "Greska pri unosu, pokusajte ponovo.";
		}
	} while (temp != 0);
	std::getchar();
}