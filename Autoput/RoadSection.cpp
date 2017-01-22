#include "RoadSection.h"


RoadSection::RoadSection(std::string begin, std::string end, double distance, bool is_working) :
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
	if ((begin == other.begin && end == other.end) || (begin == other.end&&end == other.begin))
		return true;
	return false;
}


bool RoadSection::isExistingInFile()
{
	std::ifstream file("Gradovi.txt");
	if (file.good())
	{
		std::string temp1, temp2, line; //dvije pomocne u koje cemo smjestiti dva grada i line u koju cemo ucitavati jednu po jednu liniju iz datoteke
		skipLinesInFile(file, 2);  //preskace uvodne 2 linije u datoteci
		while (getline(file, line))
		{
			temp1 = line.substr(0, 15);
			deleteBlanksInString(temp1);
			temp2 = line.substr(16, 31);
			deleteBlanksInString(temp2);
			RoadSection pom(temp1, temp2); //pomocna promjenjiva koja ce nam pomoci sa pretragom (lakse poredjenje zbog preklopljenog operatora ==), njen destruktor se poziva odmah poslije izlaska iz while petlje
			if (pom == (*this))
			{
				this->distance = std::stoi(line.substr(32, 3)); //upisuje razdaljinu izmedju dva grada u objekat   48
				if (line.substr(48, 2) == "da")
					is_working = true;
				else 
					is_working = false;
				return true;
			}
		}

	}
	else
		std::cout << "Problem sa otvaranjem datoteke koja sadrzi cvorove autoputa.";
	return false;
}
