/**
*file
*brief Header file containing class Taime
*This file contains definition and implementation of Taime, class to store time of creation and changed time
*/
#pragma once
using namespace std;
class Taime
{
	int hour;
	int min;
public:
	Taime(); 
	~Taime();
	/**
	*brief Set hours and minutes via users input from console
	*/
	void SetTime();
	/**
	*brief Output stored information
	*details Print stored fields of the Taime to the console
	*/
	void PrintTime();
	

	/**
	*brief overloaded assignment operator
	@param other Other Taime class that we assign to current Taime
	*details assign all fields of other Taime to this
	@return *this
	*/
	Taime operator =(Taime other);


	/**
	*brief Output stored information
	*details Print stored fields of the Taime to the console, using <iostream> library
	*/
	friend std::ostream& operator<< (std::ostream &out, const Taime &time);
};

#include "Taime.hxx"