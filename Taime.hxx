#include "Taime.h"
#pragma once


Taime::Taime()
{
	hour = 0;
	min = 0;
}


Taime::~Taime()
{
}

inline void Taime::SetTime()
{
	cout << "enter hour : ";
	cin >> hour;
	cout << "enter minutes:";
	cin >> min;
}

inline void Taime::PrintTime()
{
	cout<<hour << ":" << min << '\n';
}
std::ostream& operator<< (std::ostream &out, const Taime &time)
{
	// ��������� operator<< �������� ������ ������ Point, �� �� ����� ������ ������ � ������ Point
	out << time.hour<< ":" << time.min;

	return out;
}