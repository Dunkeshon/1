#pragma once
#include "FILE.h"

class mylist
{
public:
	mylist *next;
	mylist *prev;
	file info;// class with all info

	
	mylist();// ����� ����������� ������� ���������� � �������� �����
	~mylist();

};

#include "mylist.hxx"