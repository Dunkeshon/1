// class for time
#pragma once
using namespace std;
class Taime
{
	int hour;
	int min;
public:
	Taime();//������ ����� 
	~Taime();
	void SetTime();
	void PrintTime();

	Taime operator =(Taime other);
	friend std::ostream& operator<< (std::ostream &out, const Taime &time);
};

#include "Taime.hxx"