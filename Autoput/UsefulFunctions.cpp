#define _CRT_SECURE_NO_WARNINGS
#include "UsefulFunctions.h"

void skipLinesInFile(std::ifstream& dat, int n) //preskace odredjen broj linija u datoteci
{
	std::string temp;
	for (int i = 0; i < n; i++)
		getline(dat, temp);
}

void printFile(std::istream &file) //ispis kompletne datoteke
{
	std::string line;
	std::cout << std::endl;
	while (getline(file, line)) //uzima liniju po liniju i ispisuje dok se ne dodje do kraja datoteke
		std::cout << line << std::endl;
}

void deleteBlanksInString(std::string &str)
{
	str.erase(remove_if(str.begin(), str.end(), static_cast<int(*)(int)>(isspace)), str.end());
}

std::vector<std::string> readLocations()
{
	int flag = 1;
	std::vector<std::string> vec;
	std::ifstream dat("Gradovi.txt");
	std::string line, city1, city2;
	if (dat.good())
	{
		skipLinesInFile(dat, 2);
		while (getline(dat, line))
		{
			city1 = line.substr(0, 15);
			city2 = line.substr(16, 15);
			deleteBlanksInString(city1);
			deleteBlanksInString(city2);
			for (auto &it : vec) //provjerava da li je prvi grad smjesten u vektor
				if (it == city1)
				{
					flag = 0;
					break;
				}
			if (flag == 1) //ako nije smjesten(provjera preko flaga) ubacuje se u vektor - ista situacija i ispod sa varijablom city2
				vec.push_back(city1);
			flag = 1;

			for (auto &it : vec)
				if (it == city2)
				{
					flag = 0;
					break;
				}
			if (flag == 1)
				vec.push_back(city2);
			flag = 1;
		}
		dat.close();
	}
	else
		std::cout << "Problem sa otvaranjem datoteke 'Gradovi.txt'.";
	return vec;
}

std::string getPassword() //unos passworda sa *
{
	char pass[20]; int i = 0;
	while (pass[i - 1] != '\r')
	{
		pass[i] = _getch();
		std::cout << '*';
		i++;
	}
	pass[--i] = 0;
	std::string password(pass); //pretvara char array u string
	return password;
}

void printTime(std::ofstream &dat)
{
	time_t currentTime;
	struct tm *localTime;
	int minutes, seconds, hours, day, month, year;

	time(&currentTime);
	localTime = localtime(&currentTime);//uzmamo lokalno vrijeme

	day = localTime->tm_mday; //dan u mjesecu
	month = localTime->tm_mon;
	month++; //zato sto ide [0] do [11]
	year = 1900 + localTime->tm_year;
	hours = localTime->tm_hour;
	minutes = localTime->tm_min;
	seconds = localTime->tm_sec;//rasporedjujemo vrijeme po satima, minutama i sekundama

	dat << std::setw(2) << std::setfill('0') << std::right << day << '.' << std::setw(2) << std::setfill('0') << std::right << month << '.' << year << 
	".  " << std::setw(2) << std::setfill('0') << std::right << hours <<
	 ":" << std::setw(2) << std::setfill('0') << std::right << minutes << ":" << std::setw(2) << std::setfill('0') << std::right << seconds;
}
