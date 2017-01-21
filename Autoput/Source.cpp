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
		system("CLS");
		std::string username, password;
		std::cout << "Molimo radnika da unese podatke." << std::endl;
		std::cin >> username >> password;
		if (worker1.login(username, password))
		{
			worker1.print();
			i++;
		}
		else
			std::cout << "Greske pri unosu podataka, unesite podatke ponovo" << std::endl;
	} while (i==0);
	system("CLS");
	int temp;
	do
	{
		std::cout << "Izaberite funkciju:" << std::endl;
		std::cout << "Za izdavanje racuna unesite 1";
		std::cout << "Za rad sa dionicama unesite 2";
		std::cout << "Za prikaz o stanju na dionicam unesite 3";
		std::cin >> temp;
		if (temp == 1)
		{
			worker1.insertDriver();
			worker1.bill();
		}
		else if (temp == 2)
		{
			std::string loc1, loc2, c;
			std::vector<RoadSection> roads;
			//treba unijeti podatke iz datoteke u vektor
			std::cout << "Unesite dionicu za koju mijenjate funkcionalnost u formatu: lokacija-lokacija" << std::endl;
			std::cin >> loc1 >> c >> loc2;
			RoadSection road(loc1,loc2);
			//Sada treba pronaci lokaciju u vektoru i izmjeniti odrediti funkcionalnost lokacije
			for (auto& it : roads)
				if (it == road)
					it.workable();
			//treba azurirati datoteku u kojoj se nalaze lokacije
		}
		else if (temp == 3)
		{
			//uitavanje o stanju puteva iz datoteke i ispisivanje na standardni izlaz 
		}
		if (temp != 1 && temp != 2 && temp != 3 && temp != 0)
		{
			std::cout << "Greska pri unosu, pokusajte ponovo.";
		}
	} while (temp != 0);
	std::cout << "You came to toolbooth" << std::endl << "Welcome";
	std::tuple<std::time_t, std::string> location;
	worker1.ticket(location);
	std::getchar();
}