﻿
#include "pch.h"
#include <iostream>
#include "FILE.h"
#include "mylist.h"
#include "list_realisation.h"
#include <vector>
using namespace std;
//void menu();
int main()
{
	char input;// используется в меню
	//vector<int> files;//количество файлов 
	list_realisation<file> list;
	menu:
	cout << "to add a file press 1 : ";
	cin >> input;
	if (input == '1') {
		list.addEl();// два раза вызывается конструктор файла пофиксить
	}
	//если '1' то file<string,int> one; vector.pushback(1);
	// if vector.size=0 -> list_realisation <file> list(one.Get_file());
	// else list.addel();
	
	goto menu;
	//autism

	
	//one.print_info();
	
	//list.printFuncList();
	return 0;
}
/*
 void menu( )
{
	char input;
	cout << "to add a file and create a list press 1 : ";
	cin >> input;
	switch (input)
	{
	case '1':
	default:
		break;
	}
}*/
