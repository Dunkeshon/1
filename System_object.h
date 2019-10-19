//this class is a super  class for "file" and "catalog". It has common info and methods for both of them
#pragma once
#include <iostream>
#include <string>
#include "Taime.h"

using namespace std;

class System_object
{
protected:
	string _name;
	int _size;
	Taime _time;
	Taime _changed_time;
public:
	void set_common_info();
	void print_common_info();
	string Get_name() const;
	int Get_size() const;
	Taime Get_time() const;
	Taime Get_changed_time() const;
	System_object();
	~System_object();
};

#include "System_object.hxx"