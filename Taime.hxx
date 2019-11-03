/**
	*file
	*brief hxx file containing implementations of Taime.h
*/


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
/**
	*brief Set hours and minutes via users input from console
	*details Hours should be chosen from 0 to 23, minutes should be chosen from 0 to 59
*/
 void Taime::SetTime()
{
	cout << "Enter hour : ";
	cin >> hour;
	while (hour>=24)
	{
		cout << "Please, enter hours in right format : from 0 to 23 " << endl;
		cout << "Enter hour : ";
		cin >> hour;
	}
	cout << "Enter minutes:";
	cin >> min;
	while (min >= 60) {
		cout << "Please, enter minutes in right format : from 0 to 59 " << endl;
		cout << "Enter minutes:";
		cin >> min;
	}
}
 /**
	*brief Output stored information
	*details Print stored fields of the Taime to the console in form of "hours : minutes"
	*/
 void Taime::PrintTime()
{
	cout<<hour << ":" << min << '\n';
}
 /**
	*brief overloaded assignment operator
	@param other Other Taime class that we assign to current Taime
	*details assign all fields of other Taime to this
	@return *this
	*/
Taime Taime::operator=(Taime other)
{
	hour = other.hour;
	min = other.min;
	return *this;
}
/**
	*brief Output stored information
	*details Print stored fields of the Taime to the console, using <iostream> library
*/
std::ostream& operator<< (std::ostream &out, const Taime &time)
{
	out << time.hour<< ":" << time.min;
	return out;
}