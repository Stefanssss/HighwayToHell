#include "Driver.h"
#include "Worker.h"
#include "RoadSection.h"

int main()
{
	Worker worker1;
	int i = 0;
	do
	{
		std::string username, password;
		std::cout << "Molimo radnika da unese podatke:" << std::endl;
		std::cout << "	Unesite korisnicko ime: ";
		std::cin >> username;
		std::cout << "	Unesite password: ";
		password = getPassword();

		if (worker1.login(username, password))
			i = 1;
		else
			std::cout << std::endl << "Username ili password su pogresni, molimo unesite ponovo." << std::endl << std::endl;
	} while (i == 0);
	std::vector<std::string> cities = readLocations(); //ucitava u ovaj vektor sve postojece cvoroveautoputeva
	system("CLS");
	int temp;
	do
	{
		std::cout << "Podaci o radniku: " << std::endl;
		worker1.print(); std::cout << "  Status:                  prijavljen" << std::endl;
		std::cout << "\nIzaberite funkciju: " << std::endl;
		std::cout << "========================================" << std::endl;
		std::cout << "Izdavanje racuna[1]. " << std::endl;
		std::cout << "Promjena statusa odredjene dionice[2]. " << std::endl; //npr: zatvaranje dionice zbog izvodjenja radova
		std::cout << "Prikaz stanja na dionicama[3]. " << std::endl; //prohodnist i rastojanja izmedju svih dionica
		std::cout << "Evidencije o izvodjacima radova[4]. " << std::endl; //firme koje vrse radove na putu i njihovi radnici
		std::cout << "Evidencije o vozacima na autoputu[5]. " << std::endl; //ispisuje sve vozace koji se trenutno nalaze na putu
		std::cout << "Kraj[0]." << std::endl;
		std::cout << "========================================" << std::endl;
		std::cout << "Unesite opciju: ";	std::cin >> temp; std::cout << std::endl;
		if (temp == 1)
		{
			Driver dr;
			dr.insertDriver();
			dr.print();
			worker1.bill(dr,cities);
		}
		else if (temp == 2)
		{
			std::string loc1, loc2;
			bool flag = 0;
			do {
				std::cout << "  Unesite pocetnu lokaciju: ";
				std::cin >> loc1;
				std::cout << "  Unesite krajnju lokaciju: ";
				std::cin >> loc2;
				RoadSection road(loc1, loc2); //konstruktor
				if (flag = road.isExistingInFile()) //provjera da li gradovi postoje u datoteci
				{
					road.changeStatus(); //mijenja status dionice, takodje vrsi obradu podataka o kompaniji koja izvodi radove i njenim radnicima
					if (!road.getRoadStatus())//ako se status mijenja iz aktivnog u neaktivno, ubacujemo kompaniju i radnike koji odrzavaju datu dionicu
						worker1.workersOnRoad(loc1, loc2);
					else //ako je status neaktivan pa se mijenja u aktivan, brisemo kompaniju koja je odrzavala tu dionicu
						worker1.workersOnRoadDelete(loc1, loc2);

				}
				else
					std::cout << "      Jedna ili obe lokacije ne postoje u datoteci, molimo unesite ponovo." << std::endl;
			} while (flag == false);

		}
		else if (temp == 3)
		{
			std::ifstream dat("Gradovi.txt");
			printFile(dat); //ucitavanje o stanju puteva iz datoteke i ispisivanje na standardni izlaz 
		}
		else if (temp == 4)
		{
			std::ifstream file("WorkersOnRoad.txt");
			if (file.good())
			{
				printFile(file); //evidencija o izvodjacima radova
				file.close();
			}

		}
		else if (temp == 5)
		{
			std::ifstream file("Drivers.txt");
			if (file.good())
			{
				printFile(file);
				file.close();
			}
		}
		if (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 5 && temp != 0)
		{
			std::cout << "Greska pri unosu, pokusajte ponovo.";
		}
		std::cout << std::endl << std::endl;
	} while (temp != 0);
	std::getchar();
}