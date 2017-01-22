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
			deleteBlanksInString(usernameFile); //izbacuje sva prazna mjesta u stringu (Npr "OSI     " -> "OSI")!
			if (usernameFile == username) //ako smo nasli username u bazi provjeravamo password , ako password nije ok napustamo provjeru
			{
				passFile = line.substr(55, 16);
				deleteBlanksInString(passFile);
				if (passFile == password)
				{
					std::cout << "Uspjesno prijavljivanje.";
					isLoggedIn = true;
					temp = line.substr(5, 16);
					deleteBlanksInString(temp);
					this->name = temp;
					temp = line.substr(22, 16);
					deleteBlanksInString(temp);
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

void Worker::bill(const Driver &other)
{
	std::ofstream dat("Bill.txt");
	if (dat.good())
	{
		dat << name << surname;
		//treba upisati datoteku kako ce izgledati pocetni racun
	}
	else
		std::cout << "Datoteka za upis racuna nije uspjesno otvorena.";
	dat.close();
}

void Worker::workersOnRoad(const std::string& loc1, const std::string& loc2)
{
	std::string companyName, name1, surname1;
	int n;
	std::ofstream file("WorkersOnRoad.txt", std::ios::app);
	getchar();
	file << "Dionica koja se odrzava: " << loc1 << '-' << loc2 << std::endl;
	std::cout << "	Unesite ime kompanije: "; std::getline(std::cin, companyName);
	file << "Ime kompanije:  " << companyName << std::endl;
	std::cout << "	Unesite broj radnika: "; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "	Unesite ime radnika: "; std::cin >> name1;
		std::cout << "	Unesite prezime radnika: "; std::cin >> surname1;
		file << name1 << ' ';
		file << surname1 << std::endl;
	}
	file << "===========================================" << std::endl;
}



void Worker::print()
{
	Human::print();
	std::cout << "Identifikacioni broj: " << id << std::endl;
}


void Worker::workersOnRoadDelete(const std::string &loc1, const std::string &loc2)
{
	std::ifstream file("WorkersOnRoad.txt");
	std::string s1 = loc1 + '-' + loc2, s2 = loc2 + '-' + loc1; //stringovi koji sadrze nazive gradova izmedju kojih prestaju radovi
	if (file.good())
	{
		std::string str,str1; //str-pomocna promjenjiva u koju ucitavamo liniju po liniju iz datoteke,str1-ucitavamo samo nazive gradova iz linije
		std::vector<std::string> vec; //vektor stringova
		while (getline(file, str))
		{
			if (str.length() > 24) //do dvotacke 24 karatkera (citanje na osnovu formatiranog upisa u datoteku)
				if (str.substr(0, 24) == "Dionica koja se odrzava:") //ako linija pocinje sa "Dionica koja se odrzava:" pregledamo da li se iza toga nalaze nazivi gradova koji nam trebaju
				{
					str1 = str.substr(25, str.length() - 25);
					if (str1 == s1 || str1 == s2) //ako su to trazeni gradovi preskoci sve linije do sledece dionice
						while (getline(file, str))
						{
							if (str.substr(0, 24) == "Dionica koja se odrzava:" || file.eof())
								break;
						}
					if (file.eof())
						break; //ako smo izasli iz ugnijezdene while petlje i dosli do EOF izadjimo i iz glavne while petlje
				}
			vec.push_back(str);
		}
		file.close();
		std::ofstream file("WorkersOnRoad.txt"); //otvaramo datoteku koju cemo prepraviti tako da se kompanija koja je zavrsila radove vise ne nalazi u njoj
		if (file.good())
		{
			for (auto &it : vec)
				file << it << std::endl; //u datoteku upisujemo iz vektora koristeci iteratore
			file.close();
		}

	}
	else
		std::cout << "Problem sa otvaranjem datoteke 'WorkersOnRoad.txt'.";
}