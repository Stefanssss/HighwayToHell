#include "RoadSection.h"


RoadSection::RoadSection(std::string begin, std::string end, int distance, bool is_working) :
	begin(begin), end(end), distance(distance), is_working(is_working)
{
}

RoadSection::~RoadSection()
{
}

void RoadSection::print()
{
	std::cout << "Dionica :" << begin << " " << end << " ";
	if (is_working)
		std::cout << "je u funkciji";
	else
		std::cout << "nije u funkciji";
}

void RoadSection::workable()
{
	is_working = !is_working;
}

double RoadSection::getDistance()
{
	return distance;
}

bool RoadSection::operator==(const RoadSection &other)
{
	if ((begin == other.begin && end == other.end) || (begin == other.end && end == other.begin))
		return true;
	return false;
}


bool RoadSection::isExistingInFile()
{
	std::ifstream file("Gradovi.txt");
	int i = 2; //promjenjiva u kojoj cemo cuvati broj reda u kojem se dati gradovi nalaze 
	if (file.good())
	{
		std::string temp1, temp2, line; //dvije pomocne u koje cemo smjestiti dva grada i line u koju cemo ucitavati jednu po jednu liniju iz datoteke
		skipLinesInFile(file, 2);  //preskace uvodne 2 linije u datoteci
		while (getline(file, line))
		{
			temp1 = line.substr(0, 15);
			deleteBlanksInString(temp1);
			temp2 = line.substr(16, 15);
			deleteBlanksInString(temp2);
			RoadSection pom(temp1, temp2); //pomocna promjenjiva koja ce nam pomoci sa pretragom (lakse poredjenje zbog preklopljenog operatora ==), njen destruktor se poziva odmah poslije izlaska iz while petlje
			if (pom == (*this))
			{
				this->distance = std::stoi(line.substr(32, 3)); //upisuje razdaljinu izmedju dva grada u objekat

				if (line.substr(48, 2) == "da")
					is_working = true;
				else
					is_working = false;
				file.close();
				rb = i;
				return true;
			}
			i++;
		}

	}
	else
		std::cout << "Problem sa otvaranjem datoteke koja sadrzi cvorove autoputa.";
	file.close();
	return false;
}

void RoadSection::changeStatus()
{
	if (is_working == true)
		is_working = false;
	else
		is_working = true;
	
	std::ifstream file("Gradovi.txt");
	if (file.good())
	{
		int br = rb; //brojac
		std::vector<std::string> vec; //vektor u koji smjestamo liniju po liniju;
		std::string str,a ; //str-string u koji ucitavamo liniju po liniju , a-string u kojem cuvamo liniju koja se prepravlja (onako kako bi trebala biti upisana u datoteku)
		while (getline(file, str) && --br)
			vec.push_back(str);
		getline(file, str);
		a = str.substr(0, 48);
		if (is_working == true)
			a += "da";
		else
			a += "ne";
		vec.push_back(a);
		while (getline(file, str))
			vec.push_back(str);
		file.close();
		std::ofstream file("Gradovi.txt");
		if (file.good())
		{
			for (auto &it : vec)
				file << it << std::endl;
		}
		else
			std::cout << "Greska kod upisa u datoteku 'Gradovi.txt'.";

	}
	else
		std::cout << "Problem sa otvaranjem datoteke 'Gradovi.txt'";

}
