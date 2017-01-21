#pragma once
#include <string>
#include<iostream>
class RoadSection
{
public:
	RoadSection(std::string,std::string,double=0,bool=false);
	~RoadSection();
	void issuing();
	void print();
	void workable();
	double getDistance();//potrebno vracanja zbog izdavanja cijene
	bool operator ==(const RoadSection&);
private:
	std::string begin, end;
	double distance;
	bool is_working;
};

