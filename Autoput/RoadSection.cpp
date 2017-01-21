#include "RoadSection.h"


RoadSection::RoadSection(std::string begin, std::string end, double distance, bool is_working):begin(begin),end(end),distance(distance),is_working(is_working)
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
	if ((begin == other.begin && end == other.end)||(begin==other.end&&end==other.begin))
		return true;
	return false;
}
